//
// Created by tea on 10.03.16.
//

#ifndef PROTOC_BNET_BNETSERVICEGENERATOR_H
#define PROTOC_BNET_BNETSERVICEGENERATOR_H

#include <google/protobuf/stubs/common.h>
#include <cstdint>
#include <string>
#include <map>

namespace google
{
    namespace protobuf
    {
        class ServiceDescriptor;

        namespace io
        {
            class Printer;
        }

        namespace compiler
        {
            namespace cpp
            {
                struct Options;
            }
        }
    }
}

namespace pb = google::protobuf;
namespace pbcpp = pb::compiler::cpp;

class BnetServiceGenerator
{
public:
    // See generator.cc for the meaning of dllexport_decl.
    BnetServiceGenerator(const pb::ServiceDescriptor* descriptor,
                         const pbcpp::Options& options);
    ~BnetServiceGenerator();

    // Header stuff.

    // Generate the class definitions for the service's interface and the
    // stub implementation.
    void GenerateDeclarations(pb::io::Printer* printer);

    // Source file stuff.

    // Generate code that initializes the global variable storing the service's
    // descriptor.
    void GenerateDescriptorInitializer(pb::io::Printer* printer, int index);

    // Generate implementations of everything declared by GenerateDeclarations().
    void GenerateImplementation(pb::io::Printer* printer);

private:
    // Header stuff.

    // Generate the service abstract interface.
    void GenerateInterface(pb::io::Printer* printer);

    // Prints signatures for all methods in the
    void GenerateClientMethodSignatures(pb::io::Printer* printer);
    void GenerateServerMethodSignatures(pb::io::Printer* printer);

    // Source file stuff.

    void GenerateClientMethodImplementations(pb::io::Printer* printer);

    // Generate the CallMethod() method of the service.
    void GenerateServerCallMethod(pb::io::Printer* printer);
    void GenerateServerImplementations(pb::io::Printer* printer);

    std::uint32_t HashServiceName(std::string const& name);

    const pb::ServiceDescriptor* descriptor_;
    std::map<std::string, std::string> vars_;

    GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(BnetServiceGenerator);
};

#endif //PROTOC_BNET_BNETSERVICEGENERATOR_H
