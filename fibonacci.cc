#include <iostream>
#include <node.h>

using namespace std;

namespace fibonacci
{

  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void Fibonacci(const FunctionCallbackInfo<Value> &args)
  {

      int32_t n = 1000000000, t1 = 0, t2 = 1, nextTerm = 0;
      int32_t output;

      for (int i = 1; i <= n; ++i)
      {
       
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        output = nextTerm;
      }
    


    Isolate *isolate = args.GetIsolate();
    args.GetReturnValue().Set((int32_t)output);
  }

  void Initialize(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "execute", Fibonacci);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namesp