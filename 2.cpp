
  typedef unsigned int VALUE;
  VALUE _intern_value(int argc, VALUE *argv, VALUE self){
    return (self << 1) | 1;
  }
 
