---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2025
title: Monkey-patching WEBrick
propaganda: 19
class: blood
tags: ruby
---

# Monkey-patching WEBrick

In the early days of [GitHub Pages][githubpages], I found myself hosting this blog on a [Heroku][heroku] dyno, backed by the rather generous free-tier that they used have on there. Gone are those days, am I right?

Naturally, I ended up rolling my own *static site generator* in the process, which I have written in Python. This was a rather uncertain time in the Python ecosystem, because it happened to coincide with the initial introduction, and subsequent release of Python 3.

Anyway, at some point in time, when the *enshitification* of Heroku has started to rear its ugly head, I have already been a paying GitHub user for quite some time, which made me realize, that perhaps, I should just jump ship, and migrate the whole shebang to [GitHub Pages][githubpages]. A rather sensible thing to do, correct?

So, I did, but still kept using my own *static site generator* instead of [Jekyll][jekyll], which I did until about the *annus horibilis*, that happened to be the year of 2020.

The transition wasn't really anything to write home about, but I really liked the idea of not having to regenerate everything locally, then push it up in the repository, because now [Jekyll][jekyll] would take care of  that automatically for me.

## WEBrick

And, now we have arrived at the real subject matter of this post. [Jekyll][jekyll] happens to be using [WEBrick][webrick] to provide a tiny `HTTP server`, which is then used to serve the statically generated site on `localhost`. This works great, until one tries to embed a `<video>` or `<audio>`, both of which happen to require support for so called `HTTP partial content`, which happens to be more colloquially known as `range requests`.

Support for which has been implemented in a really *half-assed manner* in [WEBrick][webrick], as it turns out. I always considered this to be a relatively minor annoyance, and said to myself several times over the years, that it might be a good idea to just wait it out. Surely, someone else will come around, and fix it in due course.

I'd check on the [ruby/webrick][rubywebrick] repository on GitHub every now and then. Sadly, no dice. Until relatively recently, when this particular [pull request][webrickpr] popped up seemingly out of nowhere.

Alas, this is where the good news ends, as these changes don't really fix the issue in question, they seem to make it worse. So, I said to myself, enough is enough.

Unlike the author of the pull request, I really had no desire in battling through the politics that would be necessary in order to get a proverbial fix merged in, which left me with the only remaining viable option of cooking up, and maintaining my very own monkey-patch. Not my first rodeo, you know?

## Monkey-patch

The first order of business was to get the monkey-patch loaded before [Jekyll][jekyll] ends up booting. Unfortunately, the generated `binstub` doesn't do a `Bundler.require!`, which meant that I couldn't get away with simply doing something along the lines of:

```ruby
gem "jekyll-webrick-monkey-patch",
	path: "gems/jekyll-webrick-monkey-patch",
	require: true
```

No matter, the following did the trick just fine instead:

```ruby
require "rubygems"
require "bundler/setup"

require_relative "../lib/jekyll-webrick-monkey-patch"

load Gem.bin_path("jekyll", "jekyll")
```

With that in place, it was time for me to get started by taking a look at [WEBrick][webrick] itself, in order to figure out where and what to actually monkey-patch.

```bash
$ cd $(bundle show webrick)
$ ls
Gemfile  lib  LICENSE.txt  Rakefile  README.md  sig  webrick.gemspec
```

It didn't take awfully long before I landed in `lib/webrick/httpservlet/filehandler.rb`, which is exactly the spot where the magic seems to happen.

When investigating something like this, I like to employ a combination of so called `printf`, and `runtime debugging` by using something like `pry`.

So, I started out with something relatively basic:

```ruby
# ...

def initialize(server, local_path)
	super(server, local_path)
    @local_path = local_path
end 

# :stopdoc:

def do_GET(req, res)
    if File.extname(@local_path) == '.mp4'
		puts req 
		debugger                             
	end

    st = File::stat(@local_path)
    mtime = st.mtime
    res['etag'] = sprintf("%x-%x-%x", st.ino, st.size, st.mtime.to_i)

# ...
```

Running [Jekyll][jekyll] with these changes, led to the following output:

```bash
GET /media/2025/avp.mp4 HTTP/1.1
Connection: keep-alive
Accept-Encoding: identity;q=1, *;q=0
Accept: */*
Accept-Language: en-US,en;q=0.9
Range: bytes=0-
```

```ruby
   45: def do_GET(req, res)
   46:   if File.extname(@local_path) == '.mp4'
   47:     puts req
=> 48:     debugger
   49:   end
   50: 
   51:   st = File::stat(@local_path)
   52:   mtime = st.mtime
   53:   res['etag'] = sprintf("%x-%x-%x", st.ino, st.size, st.mtime.to_i)
```

Two things immediatelly popped out, first the `Range` header, which I expected, and then the fact that the computed `etag` header in the response, doesn't take the `Range` header into account, which in turn means that the next range request will end up raising a `HTTPStatus::NotModified`.

And, now the moment you've been all waiting for. I simply ended up disabling caching by returning `false` for all range requests, and voilà, problem solved! No fuss,  no muss!

```ruby
# frozen_string_literal: true

require "webrick"

module JekyllWebrickMonkeyPatch
  def not_modified?(req, res, mtime, etag)
    if req["Range"]
      false
    else
      super
    end 
  end 
end

WEBrick::HTTPServlet::DefaultFileHandler.prepend(JekyllWebrickMonkeyPatch)
```

Now, like I said in the beginning, I had no intentions in fixing this by trying to implement the actual specifications in order to make range requests play nice with caching. I just wanted to be able to play the media. So, if you were absolutely ready to dust off your pitchforks, please don't, it simply doesn't worth your trouble. Trust me, I should know.

One additional thing I always like to add when doing something like this; is what I like to call a proverbial   `version-check-time-bomb` (*a mouthful, I know*), which will blow up, if or when the library I happened to have *touched* has been upgraded.

```ruby
if Gem::Version.new(WEBrick::VERSION) > Gem::Version.new("1.9.1")
  raise "Please check if this monkey-patch is still necessary!"
else
  puts "Applying WEBRick monkey-patch for range requests ..."
  WEBrick::HTTPServlet::DefaultFileHandler.prepend(JekyllWebrickMonkeyPatch)
end
```

This is a very convenient way of avoiding rather nasty surprises down the line, and growing less gray hair before the age of 45, should always be considered nothing more than an added bonus.

[githubpages]: https://en.wikipedia.org/wiki/GitHub#GitHub_Pages
[heroku]: https://heroku.com
[jekyll]: https://jekyllrb.com/
[webrick]: https://en.wikipedia.org/wiki/WEBrick
[rubywebrick]: https://github.com/ruby/webrick
[webrickpr]: https://github.com/ruby/webrick/pull/169
