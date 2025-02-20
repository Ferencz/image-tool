{
  "targets": [
    {
      "target_name": "cpp_addon",
      "sources": [ "cpp_addon.cpp" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "/usr/include/opencv4"
      ],
      "libraries": [
        "/usr/lib/x86_64-linux-gnu/libopencv_core.so",
        "/usr/lib/x86_64-linux-gnu/libopencv_imgproc.so",
        "/usr/lib/x86_64-linux-gnu/libopencv_highgui.so",
        "/usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so",
        "/usr/lib/x86_64-linux-gnu/libwebp.so",
        "/usr/lib/x86_64-linux-gnu/libopencv_videoio.so"
      ],
      "cflags": [ "-frtti", "-std=c++17" ],
      "cflags_cc": [ "-frtti", "-std=c++17" ],
      "cflags!": [ "-fno-exceptions", "-fno-rtti" ],
      "cflags_cc!": [ "-fno-exceptions", "-fno-rtti" ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ]
    }
  ]
}
