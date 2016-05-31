//
// Created by tea on 10.03.16.
//

#include <vector>
#include "BnetFileGenerator.h"
#include "google/protobuf/compiler/cpp/cpp_helpers.h"
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/descriptor.pb.h>

#include "BnetCodeGenerator.h"

bool BnetCodeGenerator::Generate(pb::FileDescriptor const* file, std::string const& parameter,
                                 pbc::GeneratorContext* generator_context, std::string* error) const
{
    std::vector<std::pair<std::string, std::string>> options;
    google::protobuf::compiler::ParseGeneratorParameter(parameter, &options);

    // -----------------------------------------------------------------
    // parse generator options

    google::protobuf::compiler::cpp::Options file_options;

    for (int i = 0; i < options.size(); i++)
    {
        if (options[i].first == "dllexport_decl")
        {
            file_options.dllexport_decl = options[i].second;
        }
        else if (options[i].first == "safe_boundary_check")
        {
            file_options.safe_boundary_check = true;
        }
        else
        {
            *error = "Unknown generator option: " + options[i].first;
            return false;
        }
    }

    // -----------------------------------------------------------------


    std::string basename = google::protobuf::compiler::cpp::StripProto(file->name());
    basename.append(".pb");

    BnetFileGenerator file_generator(file, file_options);

    // Generate header.
    {
        pb::scoped_ptr <google::protobuf::io::ZeroCopyOutputStream> output(
            generator_context->Open(basename + ".h"));
        google::protobuf::io::Printer printer(output.get(), '$');
        file_generator.GenerateHeader(&printer);
    }

    // Generate cc file.
    {
        pb::scoped_ptr <google::protobuf::io::ZeroCopyOutputStream> output(
            generator_context->Open(basename + ".cc"));
        google::protobuf::io::Printer printer(output.get(), '$');
        file_generator.GenerateSource(&printer);
    }

    return true;
}

