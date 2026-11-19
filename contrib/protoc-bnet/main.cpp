#include "BnetCodeGenerator.h"
#include <google/protobuf/compiler/plugin.h>

int main(int argc, char* argv[])
{
    BnetCodeGenerator gen;
    return google::protobuf::compiler::PluginMain(argc, argv, &gen);
}
