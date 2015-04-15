#include <ruby.h>
#include <stdio.h>

//#define PRINT_EVENTS

#ifdef PRINT_EVENTS
inline static const char *
get_event_name(rb_event_flag_t _event)
{
  switch (_event) {
    case RUBY_EVENT_LINE:
      return "line";
    case RUBY_EVENT_CLASS:
      return "class";
    case RUBY_EVENT_END:
      return "end";
    case RUBY_EVENT_CALL:
      return "call";
    case RUBY_EVENT_RETURN:
      return "return";
    case RUBY_EVENT_C_CALL:
      return "c-call";
    case RUBY_EVENT_C_RETURN:
      return "c-return";
    case RUBY_EVENT_RAISE:
      return "raise";
    default:
      return "unknown";
  }
}
#endif

static void
debug_event_hook(rb_event_flag_t event, VALUE data, VALUE self, ID mid, VALUE klass)
{
#ifdef PRINT_EVENTS
    char *file = (char*)rb_sourcefile();
    int line = rb_sourceline();

    fprintf(stderr, "%s:%d [%s] %s\n", file, line, get_event_name(event), rb_id2name(mid));
#endif
}

void Init_debug_event_hook()
{
    rb_add_event_hook(debug_event_hook, RUBY_EVENT_ALL, Qnil);
}