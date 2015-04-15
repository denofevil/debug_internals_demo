require 'event_hook'

EventHook.new {
  def process(*args)
    puts args
  end
}.start_hook
