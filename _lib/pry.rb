# frozen_string_literal: true

require "pry"
require "pry-nav"
require "binding_of_caller"

Pry.commands.tap do |commands|
  commands.alias_command("c", "continue")
  commands.alias_command("s", "step")
  commands.alias_command("n", "next")
end

module Kernel
  def debugger
    Pry.start(binding.of_caller(1))
  end
end
