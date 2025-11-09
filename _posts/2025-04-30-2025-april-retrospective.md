---
layout: post
typora-root-url: ..
typora-copy-images-to: ../media/2025
title: 2025 April Retrospective
propaganda: megan2
class: blood megan
music: CduA0TULnow
tags: retrospective
---

# 2025 April Retrospective

It feels like I was writing up last month's retrospective just like a day or two ago, yet here I am again. Where did April go? And naturally, I am not talking about April Lavigne, when I say this.

## M3GAN 2.0

I might have said this before, but [James Wan][jameswan] is undoubtedly one of the great masters of horror. He has proven his weight in gold time and time again.

Even though, I am not a big fan of the *comedy-horror genre*, I did end up enjoying the [first M3GAN][megan], this is of course yet another testament to James' involvement in its making.

[M3GAN 2.0][megan2] goes beyond the simple more of the same feeling that most horror franchises seem to end up suffering from, and based on the trailer alone it's set out to be a real banger in every way of word.

{% include youtube.html id="IYLHdEzsk1s" %}

## Xanadu Next

Not too long ago, I was lamenting about missing some hidden gems in terms of games of the late 90s and early 2000s. So, here's another one. An ARPG no less from way back in 2005.

I am talking about [Xanadu Next][xanadunext], as you might have guessed already.

{% include youtube.html id="vbav9ks2N7U" %}

## 2000

Speaking of the 2000s, [Ahoy][ahoy] has dropped a pretty cool retrospective.

{% include youtube.html id="fuSRjyR_ZJU" %}

## Nintendo Switch 2.0

What is it with this month? Yet another 2.0 on the block? I kid, I kid.

{% include youtube.html id="9flte56erE8" %}

I have to confess that I didn't pre-order one, but most certainly will get my hands on one, once all the fuss and muss dies out. Which will probably only happen after the release. Besides, I am not that hyped by another [Mario Kart][mariokart] game; however the open-world aspects of it do seem be rather intriguing.

{% include youtube.html id="3pE23YTYEZM" %}

What about the pricing? The pricing is fair and square as far as I am concerned. Companies like Nintendo and game companies in general do not have a lot of ways at their disposal to generate any sort of recurring revenue, as a direct result it makes perfect sense to raise prices and/or find alternative ways to monetize things.

Now, to some people this might appear to be nothing less than corporate greed, and that's perfectly fine, everybody is entitled to have their own opinions, even if they aren't consistent with the reality of running a business the size of Nintendo.

All this reminded me of the discussions around the time of the original Nintendo Switch. Everybody and their grandma' was crying about how underpowered it was, and how nobody is going to buy, nor will companies port any games resembling AAA to it. And, then when it started selling like hot cakes, the same people who were whining about it ended up porting the games. You'd have to be crazy to sleep on a market of tens of millions of consoles. Funny how things have their way of working themselves out, right?

## Stronghold Crusader: Definitive Edition

More Stronghold Crusader news? You've got it, fam!

{% include youtube.html id="36gk9mL5OBA" %}

More AI lords are always welcome.

{% include youtube.html id="um9P-_v5RSM" %}

## Ruby VM

I've been writing Ruby since around 2008 or so, and never ever realized that one can interact with the Ruby VM at runtime and take a peek at the underlying opcodes by dissembling a block of code.

```ruby
$ irb
?> def f(x, y)
?>   [x, y].sum
>> end
=> :f
>> n = RubyVM::InstructionSequence.of(method(:f))
=> <RubyVM::InstructionSequence:f@(irb):1>
>> puts n.disasm
== disasm: #<ISeq:f@(irb):1 (1,0)-(3,3)> (catch: FALSE)
local table (size: 2, argc: 2 [opts: 0, rest: -1, post: 0, block: -1, kw: -1@-1, kwrest: -1])
[ 2] x@0<Arg>   [ 1] y@1<Arg>
0000 getlocal_WC_0                x@0                                 (   2)[LiCa]
0002 getlocal_WC_0                y@1
0004 newarray                     2
0006 opt_send_without_block       <callinfo!mid:sum, argc:0, ARGS_SIMPLE>, <callcache>
0009 leave                                                            (   3)[Re]
=> nil
```

Be right back while I go and end up validating some of my day-to-day assumptions about using certain constructs or paradigms if you will. It goes to show that Ruby is a pretty intuitive and solid language in terms of its design all things considered; I never felt like I needed to awe a gander at the underlying opcodes until relatively recently.

[megan]: https://en.wikipedia.org/wiki/M3GAN
[megan2]: https://en.wikipedia.org/wiki/M3GAN_2.0
[xanadunext]: https://en.wikipedia.org/wiki/Xanadu_Next
[ahoy]: https://www.youtube.com/@XboxAhoy
[mariokart]: https://en.wikipedia.org/wiki/Mario_Kart
[jameswan]: https://en.wikipedia.org/wiki/James_Wan
