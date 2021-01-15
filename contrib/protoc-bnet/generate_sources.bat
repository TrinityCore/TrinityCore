FOR %%P IN (proto\global_extensions\*.proto) DO (
  protoc.exe --plugin=protoc-gen-bnet=protoc-gen-bnet.exe --bnet_out=dllexport_decl=TC_PROTO_API:buildproto -Iproto %%P
)
FOR %%P IN (proto\*.proto) DO (
  protoc.exe --plugin=protoc-gen-bnet=protoc-gen-bnet.exe --bnet_out=dllexport_decl=TC_PROTO_API:buildproto -Iproto %%P
)
