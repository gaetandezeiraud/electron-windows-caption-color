#include <node.h>
#include <nan.h>

#ifdef _WIN32
    #pragma comment(lib, "dwmapi.lib")
    
    #include <windows.h>
    #include <dwmapi.h>
#endif

using namespace v8;

void SetCaptionColor(const FunctionCallbackInfo<Value>& args)
{
#ifdef _WIN32
    if(args.Length() == 2 || !args[0]->IsObject() || !args[1]->IsNumber() || !args[2]->IsNumber() || !args[3]->IsNumber())
    {
        Nan::ThrowError("Invalid arguments.");
        return;
    }

    v8::Local<v8::Context> context = args.GetIsolate()->GetCurrentContext();

    // Get HWND
    auto windowHandleBuffer = args[0]->ToObject(context).ToLocalChecked();
    char* bufferData = node::Buffer::Data(windowHandleBuffer);

    uint32_t handle = *reinterpret_cast<uint32_t*>(bufferData);
    HWND hwnd = (HWND)handle;

    // Generate the color
    int red = args[1]->NumberValue(context).ToChecked();
    int green = args[2]->NumberValue(context).ToChecked();
    int blue = args[3]->NumberValue(context).ToChecked();

    COLORREF color = RGB(red, green, blue);

    // Apply the color
    enum DWMWINDOWATTRIBUTE
    {
        DWMWA_CAPTION_COLOR = 35
    };

    DwmSetWindowAttribute(hwnd, DWMWINDOWATTRIBUTE::DWMWA_CAPTION_COLOR, &color, sizeof(color));
#endif
}

void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "SetCaptionColor", SetCaptionColor);
}

NODE_MODULE_INIT() {
    init(exports);
}