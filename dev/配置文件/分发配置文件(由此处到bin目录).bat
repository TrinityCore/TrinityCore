rem 注意此批处理,必须设置文本格式为ANSI,不然乱码,无法正常执行
copy /Y "D:\Program Files (x86)\WOWDIY\XCore\dev\配置文件\bnetserver.conf" "D:\Program Files (x86)\WOWDIY\XCore\out\build\x64-Debug\bin"
copy /Y "D:\Program Files (x86)\WOWDIY\XCore\dev\配置文件\worldserver.conf" "D:\Program Files (x86)\WOWDIY\XCore\out\build\x64-Debug\bin"


copy /Y "D:\Program Files (x86)\WOWDIY\XCore\dev\配置文件\bnetserver.conf" "D:\Program Files (x86)\WOWDIY\XCore\out\build\x64-Release\bin"
copy /Y "D:\Program Files (x86)\WOWDIY\XCore\dev\配置文件\worldserver.conf" "D:\Program Files (x86)\WOWDIY\XCore\out\build\x64-Release\bin"
