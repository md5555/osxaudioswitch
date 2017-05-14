#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
 
// node headers
#include <nan.h>
#include <v8.h>
#include <node.h>
#include <unistd.h>
#include <string.h>
#include "audio_switch.h"

using namespace node;
using namespace v8;

v8::Isolate* isolate;
 
void SwitchOutput(const v8::FunctionCallbackInfo<v8::Value>& args) {

    Nan::Utf8String name(args[0]);
 
    const char * str = *name;

    switchOutput(str);
} 

void ResetOutput(const v8::FunctionCallbackInfo<v8::Value>& args) {

    resetOutput();
}

Handle<Value> Initialize(Handle<Object> target)
{
    isolate = Isolate::GetCurrent(); 

    target->Set(String::NewFromUtf8(Isolate::GetCurrent(), "switchOutput"),
        FunctionTemplate::New(Isolate::GetCurrent(), SwitchOutput)->GetFunction());

    target->Set(String::NewFromUtf8(Isolate::GetCurrent(), "resetOutput"),
        FunctionTemplate::New(Isolate::GetCurrent(), ResetOutput)->GetFunction());


    return True(Isolate::GetCurrent());
}

NODE_MODULE(osxaudioswitch, Initialize);
