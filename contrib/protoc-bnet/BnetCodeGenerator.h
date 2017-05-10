//
// Created by tea on 10.03.16.
//

#ifndef PROTOC_BNET_BNETCODEGENERATOR_H
#define PROTOC_BNET_BNETCODEGENERATOR_H

#include <google/protobuf/compiler/code_generator.h>
#include <string>

namespace pb = google::protobuf;
namespace pbc = pb::compiler;

class BnetCodeGenerator : public pbc::CodeGenerator
{
public:
    bool Generate(pb::FileDescriptor const* file,
                  std::string const& parameter,
                  pbc::GeneratorContext* generator_context,
                  std::string* error) const override;

};

#endif //PROTOC_BNET_BNETCODEGENERATOR_H
