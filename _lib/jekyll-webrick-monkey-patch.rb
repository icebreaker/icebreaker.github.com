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

if Gem::Version.new(WEBrick::VERSION) > Gem::Version.new("1.9.1")
  raise "You seem to have upgraded WEBrick, please check if this monkey-patch is still necessary!"
else
  puts "Applying WEBRick monkey-patch for range requests ..."
  WEBrick::HTTPServlet::DefaultFileHandler.prepend(JekyllWebrickMonkeyPatch)
end
