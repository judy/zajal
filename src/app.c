#include "ruby.h"
#include "ofMain.h"
#include "zajal.h"

/* global app module */
VALUE zj_mApp;

/*  globals */
VALUE _zj_value_window_title = Qnil;
VALUE _zj_value_vertical_sync = Qtrue;
VALUE _zj_value_cursor_visible = Qtrue;
VALUE _zj_value_fullscreen_mode = Qfalse;

VALUE zj_width(int argc, VALUE* argv, VALUE klass) {
  VALUE w;
  rb_scan_args(argc, argv, "01", &w);
  
  if(NIL_P(w)) {
    /*  called without arguments, return current width */
    return rb_float_new(ofGetWidth());
    
  } else {
    /*  called with argument, set window width */
    ofSetWindowShape(NUM2INT(w), ofGetHeight());
    
  }
  
  return Qnil;
}

VALUE zj_height(int argc, VALUE* argv, VALUE klass) {
  VALUE h;
  rb_scan_args(argc, argv, "01", &h);
  
  if(NIL_P(h)) {
    /*  called without arguments, return current height */
    return rb_float_new(ofGetHeight());
    
  } else {
    /*  called with argument, set window width */
    ofSetWindowShape(ofGetWidth(), NUM2INT(h));
    
  }
  
  return Qnil;
}

VALUE zj_size(int argc, VALUE* argv, VALUE klass) {
  VALUE w, h;
  rb_scan_args(argc, argv, "02", &w, &h);
  
  if(NIL_P(w) && NIL_P(h)) {
    /*  called without argument, return current size */
    VALUE size_ary = rb_ary_new();
    rb_ary_push(size_ary, INT2NUM(ofGetWidth()));
    rb_ary_push(size_ary, INT2NUM(ofGetHeight()));
    return size_ary;
    
  } else if(NIL_P(h)) {
    /*  called with one argument, set window size to square */
    ofSetWindowShape(NUM2INT(w), NUM2INT(w));
    
  } else {
    /*  called with two arguments, set window size to rectangle */
    ofSetWindowShape(NUM2INT(w), NUM2INT(h));
    
  }
  
  return Qnil;
}

VALUE zj_vertical_sync(int argc, VALUE* argv, VALUE klass) {
  VALUE new_vertical_sync;
  rb_scan_args(argc, argv, "01", &new_vertical_sync);
  
  if(NIL_P(new_vertical_sync)) {
    /*  method called without argument, treat as a getter */
    return _zj_value_vertical_sync;
    
  } else {
    /*  method called with argument, treat as setter */
    _zj_value_vertical_sync = new_vertical_sync;
    ofSetVerticalSync(RTEST(new_vertical_sync));
    return Qnil;
    
  }
}

VALUE zj_time(VALUE self) {
  return INT2NUM(ofGetElapsedTimeMillis());
}

VALUE zj_frame(VALUE self) {
  return INT2NUM(ofGetFrameNum());
}

VALUE zj_framerate(int argc, VALUE* argv, VALUE klass) {
  VALUE new_framerate;
  rb_scan_args(argc, argv, "01", &new_framerate);
  
  if(NIL_P(new_framerate)) {
    /*  method called without argument, treat as a getter */
    return rb_float_new(ofGetFrameRate());
    
  } else {
    /*  method called with argument, treat as setter */
    ofSetFrameRate(NUM2DBL(new_framerate));
    return Qnil;
    
  }
}

VALUE zj_title(int argc, VALUE* argv, VALUE klass) {
  VALUE new_title;
  rb_scan_args(argc, argv, "01", &new_title);
  
  if(NIL_P(new_title)) {
    /*  method called without argument, treat as a getter */
    return _zj_value_window_title;
    
  } else {
    /*  method called with argument, treat as setter */
    _zj_value_window_title = new_title;
    ofSetWindowTitle(StringValuePtr(_zj_value_window_title));
    return Qnil;
    
  }
}

VALUE zj_cursor(int argc, VALUE* argv, VALUE self) {
  VALUE cursor_visible;
  rb_scan_args(argc, argv, "01", &cursor_visible);
  
  if(NIL_P(cursor_visible)) {
    /*  method called without argument, treat as a getter */
    return _zj_value_cursor_visible;
    
  } else {
    /*  method called with argument, treat as setter */
    _zj_value_cursor_visible = cursor_visible;
    RTEST(_zj_value_cursor_visible) ? ofShowCursor() : ofHideCursor();
    return Qnil;
    
  }
}

VALUE zj_fullscreen(int argc, VALUE* argv, VALUE self) {
  VALUE fullscreen_mode;
  rb_scan_args(argc, argv, "01", &fullscreen_mode);
  
  if(NIL_P(fullscreen_mode)) {
    /*  method called without argument, treat as a getter */
    return _zj_value_fullscreen_mode;
    
  } else {
    /*  method called with argument, treat as setter */
    _zj_value_fullscreen_mode = fullscreen_mode;
    ofSetFullscreen(RTEST(_zj_value_fullscreen_mode));
    return Qnil;
    
  }
}

VALUE zj_screen_width(VALUE self) {
  return INT2NUM(ofGetScreenWidth());
}

VALUE zj_screen_height(VALUE self) {
  return INT2NUM(ofGetScreenHeight());
}

VALUE zj_window_x(int argc, VALUE* argv, VALUE self) {
  VALUE new_x;
  rb_scan_args(argc, argv, "01", &new_x);
  
  if(NIL_P(new_x)) {
    /*  method called without argument, treat as a getter */
    return INT2NUM(ofGetWindowPositionX());
    
  } else {
    /*  method called with argument, treat as setter */
    ofSetWindowPosition(NUM2INT(new_x), ofGetWindowPositionY());
    return Qnil;
    
  }
}

VALUE zj_window_y(int argc, VALUE* argv, VALUE self) {
  VALUE new_y;
  rb_scan_args(argc, argv, "01", &new_y);
  
  if(NIL_P(new_y)) {
    /*  method called without argument, treat as a getter */
    return INT2NUM(ofGetWindowPositionY());
    
  } else {
    /*  method called with argument, treat as setter */
    ofSetWindowPosition(ofGetWindowPositionX(), NUM2INT(new_y));
    return Qnil;
    
  }
}

VALUE zj_segfault(VALUE self) {
  int* iWillCrash;
  int a = iWillCrash[92089];
}


void Init_App() {
  zj_mApp = rb_define_module_under(zj_mZajal, "App");
  rb_define_module_under(zj_mApp, "Internals");
  
  rb_define_private_method(zj_mApp, "segfault", RB_FUNC(zj_segfault), 0);
  rb_define_private_method(zj_mApp, "height", RB_FUNC(zj_height), -1);
  rb_define_private_method(zj_mApp, "width", RB_FUNC(zj_width), -1);
  rb_define_private_method(zj_mApp, "size", RB_FUNC(zj_size), -1);
  rb_define_private_method(zj_mApp, "time", RB_FUNC(zj_time), 0);
  rb_define_private_method(zj_mApp, "frame", RB_FUNC(zj_frame), 0);
  rb_define_private_method(zj_mApp, "framerate", RB_FUNC(zj_framerate), -1);
  rb_define_private_method(zj_mApp, "vertical_sync", RB_FUNC(zj_vertical_sync), -1);
  rb_define_private_method(zj_mApp, "title", RB_FUNC(zj_title), -1);
  rb_define_private_method(zj_mApp, "fullscreen", RB_FUNC(zj_fullscreen), -1);
  rb_define_private_method(zj_mApp, "cursor", RB_FUNC(zj_cursor), -1);
  rb_define_private_method(zj_mApp, "screen_width", RB_FUNC(zj_screen_width), 0);
  rb_define_private_method(zj_mApp, "screen_height", RB_FUNC(zj_screen_height), 0);
  rb_define_private_method(zj_mApp, "window_x", RB_FUNC(zj_window_x), -1);
  rb_define_private_method(zj_mApp, "window_y", RB_FUNC(zj_window_y), -1);
}