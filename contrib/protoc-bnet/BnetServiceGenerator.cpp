//
// Created by tea on 10.03.16.
//

#include "BnetServiceGenerator.h"
#include "method_options.pb.h"
#include "service_options.pb.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/compiler/cpp/cpp_helpers.h>
#include "google/protobuf/compiler/cpp/cpp_options.h"

BnetServiceGenerator::BnetServiceGenerator(pb::ServiceDescriptor const* descriptor, pbcpp::Options const& options) : descriptor_(descriptor)
{
    vars_["classname"] = descriptor_->name();
    vars_["full_name"] = descriptor_->full_name();
    if (options.dllexport_decl.empty())
        vars_["dllexport"] = "";
    else
        vars_["dllexport"] = options.dllexport_decl + " ";

    if (descriptor_->options().HasExtension(Battlenet::service_options))
        vars_["original_hash"] = "  typedef std::integral_constant<uint32, 0x" + pb::ToUpper(pb::ToHex(HashServiceName(descriptor_->options().GetExtension(Battlenet::service_options).descriptor_name()))) + "u> OriginalHash;\n";
    else
        vars_["original_hash"] = "";
    vars_["name_hash"] = "  typedef std::integral_constant<uint32, 0x" + pb::ToUpper(pb::ToHex(HashServiceName(descriptor_->full_name()))) + "u> NameHash;\n";
}

BnetServiceGenerator::~BnetServiceGenerator() = default;

void BnetServiceGenerator::GenerateDeclarations(pb::io::Printer* printer)
{
    GenerateInterface(printer);
}

void BnetServiceGenerator::GenerateInterface(pb::io::Printer* printer)
{
    printer->Print(vars_,
        "class $dllexport$$classname$ : public ServiceBase\n"
        "{\n"
        " public:\n"
        "\n"
        "  explicit $classname$(bool use_original_hash);\n"
        "  virtual ~$classname$();\n"
        "\n"
        "$original_hash$"
        "$name_hash$");

    printer->Indent();

    printer->Print(vars_,
        "\n"
        "static google::protobuf::ServiceDescriptor const* descriptor();\n"
        "\n");

    if (!descriptor_->options().HasExtension(Battlenet::sdk_service_options) || descriptor_->options().GetExtension(Battlenet::sdk_service_options).inbound())
    {
        printer->Print(vars_,
            "// client methods --------------------------------------------------\n");

        GenerateClientMethodSignatures(printer);

        printer->Print(vars_, "\n");
    }

    printer->Print("void CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) final;\n");

    if (!descriptor_->options().HasExtension(Battlenet::sdk_service_options) || descriptor_->options().GetExtension(Battlenet::sdk_service_options).outbound())
    {
        printer->Outdent();

        printer->Print(
            "\n"
            " protected:\n  ");

        printer->Indent();

        printer->Print("// server methods --------------------------------------------------\n");

        GenerateServerMethodSignatures(printer);
    }

    printer->Outdent();

    printer->Print(vars_,
        "\n"
        " private:\n"
        "  uint32 service_hash_;\n"
        "\n"
        "  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS($classname$);\n"
        "};\n");
}

void BnetServiceGenerator::GenerateClientMethodSignatures(pb::io::Printer* printer)
{
    for (int i = 0; i < descriptor_->method_count(); i++)
    {
        pb::MethodDescriptor const* method = descriptor_->method(i);
        if (!method->options().HasExtension(Battlenet::method_options))
            continue;

        std::map<std::string, std::string> sub_vars;
        sub_vars["name"] = method->name();
        sub_vars["full_name"] = descriptor_->name() + "." + method->name();
        sub_vars["method_id"] = pb::SimpleItoa(method->options().GetExtension(Battlenet::method_options).id());
        sub_vars["input_type"] = pbcpp::ClassName(method->input_type(), true);
        sub_vars["output_type"] = pbcpp::ClassName(method->output_type(), true);
        sub_vars["input_type_name"] = method->input_type()->full_name();

        if (method->output_type()->name() != "NO_RESPONSE")
            printer->Print(sub_vars, "void $name$($input_type$ const* request, std::function<void($output_type$ const*)> responseCallback, bool client = false, bool server = false);\n");
        else
            printer->Print(sub_vars, "void $name$($input_type$ const* request, bool client = false, bool server = false);\n");
    }
}

void BnetServiceGenerator::GenerateServerMethodSignatures(pb::io::Printer* printer)
{
    for (int i = 0; i < descriptor_->method_count(); i++)
    {
        pb::MethodDescriptor const* method = descriptor_->method(i);
        if (!method->options().HasExtension(Battlenet::method_options))
            continue;

        std::map<std::string, std::string> sub_vars;
        sub_vars["name"] = method->name();
        sub_vars["input_type"] = pbcpp::ClassName(method->input_type(), true);
        sub_vars["output_type"] = pbcpp::ClassName(method->output_type(), true);

        if (method->output_type()->name() != "NO_RESPONSE")
            printer->Print(sub_vars, "virtual uint32 Handle$name$($input_type$ const* request, $output_type$* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation);\n");
        else
            printer->Print(sub_vars, "virtual uint32 Handle$name$($input_type$ const* request);\n");
    }
}

// ===================================================================

void BnetServiceGenerator::GenerateDescriptorInitializer(pb::io::Printer* printer, int index)
{
    std::map<std::string, std::string> vars;
    vars["classname"] = descriptor_->name();
    vars["index"] = pb::SimpleItoa(index);

    printer->Print(vars, "$classname$_descriptor_ = file->service($index$);\n");
}

// ===================================================================

void BnetServiceGenerator::GenerateImplementation(pb::io::Printer* printer)
{
    printer->Print(vars_,
        "$classname$::$classname$(bool use_original_hash) : service_hash_(use_original_hash ? OriginalHash::value : NameHash::value) {\n"
        "}\n"
        "\n"
        "$classname$::~$classname$() {\n"
        "}\n"
        "\n"
        "google::protobuf::ServiceDescriptor const* $classname$::descriptor() {\n"
        "  protobuf_AssignDescriptorsOnce();\n"
        "  return $classname$_descriptor_;\n"
        "}\n"
        "\n");

    if (!descriptor_->options().HasExtension(Battlenet::sdk_service_options) || descriptor_->options().GetExtension(Battlenet::sdk_service_options).inbound())
        GenerateClientMethodImplementations(printer);

    if (!descriptor_->options().HasExtension(Battlenet::sdk_service_options) || descriptor_->options().GetExtension(Battlenet::sdk_service_options).outbound())
    {
        GenerateServerCallMethod(printer);
        GenerateServerImplementations(printer);
    }
    else
    {
        printer->Print(vars_,
            "void $classname$::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer /*buffer*/) {\n"
            "  TC_LOG_ERROR(\"service.protobuf\", \"%s Server tried to call server method %u\",\n"
            "    GetCallerInfo().c_str(), methodId);\n"
            "}\n"
            "\n");
    }
}

void BnetServiceGenerator::GenerateClientMethodImplementations(pb::io::Printer* printer)
{
    for (int i = 0; i < descriptor_->method_count(); i++)
    {
        pb::MethodDescriptor const* method = descriptor_->method(i);
        if (!method->options().HasExtension(Battlenet::method_options))
            continue;

        std::map<std::string, std::string> sub_vars;
        sub_vars["classname"] = vars_["classname"];
        sub_vars["name"] = method->name();
        sub_vars["full_name"] = descriptor_->name() + "." + method->name();
        sub_vars["method_id"] = pb::SimpleItoa(method->options().GetExtension(Battlenet::method_options).id());
        sub_vars["input_type"] = pbcpp::ClassName(method->input_type(), true);
        sub_vars["output_type"] = pbcpp::ClassName(method->output_type(), true);
        sub_vars["input_type_name"] = method->input_type()->full_name();

        if (method->output_type()->name() != "NO_RESPONSE")
        {
            printer->Print(sub_vars,
                "void $classname$::$name$($input_type$ const* request, std::function<void($output_type$ const*)> responseCallback, bool client /*= false*/, bool server /*= false*/) {\n"
                "  TC_LOG_DEBUG(\"service.protobuf\", \"%s Server called client method $full_name$($input_type_name${ %s })\",\n"
                "    GetCallerInfo().c_str(), request->ShortDebugString().c_str());\n"
                "  std::function<void(MessageBuffer)> callback = [responseCallback](MessageBuffer buffer) -> void {\n"
                "    $output_type$ response;\n"
                "    if (response.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize()))\n"
                "      responseCallback(&response);\n"
                "  };\n"
                "  SendRequest(service_hash_, $method_id$ | (client ? 0x40000000 : 0) | (server ? 0x80000000 : 0), request, std::move(callback));\n"
                "}\n"
                "\n");
        }
        else
        {
            printer->Print(sub_vars,
                "void $classname$::$name$($input_type$ const* request, bool client /*= false*/, bool server /*= false*/) {\n"
                "  TC_LOG_DEBUG(\"service.protobuf\", \"%s Server called client method $full_name$($input_type_name${ %s })\",\n"
                "    GetCallerInfo().c_str(), request->ShortDebugString().c_str());\n"
                "  SendRequest(service_hash_, $method_id$ | (client ? 0x40000000 : 0) | (server ? 0x80000000 : 0), request);\n"
                "}\n"
                "\n");
        }
    }
}

void BnetServiceGenerator::GenerateServerCallMethod(pb::io::Printer* printer)
{
    printer->Print(vars_,
        "void $classname$::CallServerMethod(uint32 token, uint32 methodId, MessageBuffer buffer) {\n"
        "  switch(methodId & 0x3FFFFFFF) {\n");

    for (int i = 0; i < descriptor_->method_count(); i++)
    {
        pb::MethodDescriptor const* method = descriptor_->method(i);
        if (!method->options().HasExtension(Battlenet::method_options))
            continue;

        std::map<std::string, std::string> sub_vars;
        sub_vars["classname"] = vars_["classname"];
        sub_vars["name"] = method->name();
        sub_vars["full_name"] = descriptor_->name() + "." + method->name();
        sub_vars["method_id"] = pb::SimpleItoa(method->options().GetExtension(Battlenet::method_options).id());
        sub_vars["input_type"] = pbcpp::ClassName(method->input_type(), true);
        sub_vars["output_type"] = pbcpp::ClassName(method->output_type(), true);
        sub_vars["input_type_name"] = method->input_type()->full_name();
        sub_vars["output_type_name"] = method->output_type()->full_name();

        printer->Print(sub_vars,
            "    case $method_id$: {\n"
            "      $input_type$ request;\n"
            "      if (!request.ParseFromArray(buffer.GetReadPointer(), buffer.GetActiveSize())) {\n"
            "        TC_LOG_DEBUG(\"service.protobuf\", \"%s Failed to parse request for $full_name$ server method call.\", GetCallerInfo().c_str());\n"
            "        SendResponse(service_hash_, methodId, token, ERROR_RPC_MALFORMED_REQUEST);\n"
            "        return;\n"
            "      }\n"
            );

        if (method->output_type()->name() != "NO_RESPONSE")
        {
            printer->Print(sub_vars,
                "      TC_LOG_DEBUG(\"service.protobuf\", \"%s Client called server method $full_name$($input_type_name${ %s }).\",\n"
                "        GetCallerInfo().c_str(), request.ShortDebugString().c_str());\n"
                "      std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)> continuation = [token, methodId](ServiceBase* service, uint32 status, ::google::protobuf::Message const* response)\n"
                "      {\n"
                "        ASSERT(response->GetDescriptor() == $output_type$::descriptor());\n"
                "        $classname$* self = static_cast<$classname$*>(service);\n"
                "        TC_LOG_DEBUG(\"service.protobuf\", \"%s Client called server method $full_name$() returned $output_type_name${ %s } status %u.\",\n"
                "          self->GetCallerInfo().c_str(), response->ShortDebugString().c_str(), status);\n"
                "        if (!status)\n"
                "          self->SendResponse(self->service_hash_, methodId, token, response);\n"
                "        else\n"
                "          self->SendResponse(self->service_hash_, methodId, token, status);\n"
                "      };\n"
                "      $output_type$ response;\n"
                "      uint32 status = Handle$name$(&request, &response, continuation);\n"
                "      if (continuation)\n"
                "        continuation(this, status, &response);\n"
            );
        }
        else
        {
            printer->Print(sub_vars,
                "      uint32 status = Handle$name$(&request);\n"
                "      TC_LOG_DEBUG(\"service.protobuf\", \"%s Client called server method $full_name$($input_type_name${ %s }) status %u.\",\n"
                "        GetCallerInfo().c_str(), request.ShortDebugString().c_str(), status);\n"
                "      if (status)\n"
                "        SendResponse(service_hash_, methodId, token, status);\n");
        }

        printer->Print(sub_vars,
            "      break;\n"
            "    }\n");
    }

    printer->Print(vars_,
        "    default:\n"
        "      TC_LOG_ERROR(\"service.protobuf\", \"Bad method id %u.\", methodId);\n"
        "      SendResponse(service_hash_, methodId, token, ERROR_RPC_INVALID_METHOD);\n"
        "      break;\n"
        "    }\n"
        "}\n"
        "\n");
}

void BnetServiceGenerator::GenerateServerImplementations(pb::io::Printer* printer)
{
    for (int i = 0; i < descriptor_->method_count(); i++)
    {
        pb::MethodDescriptor const* method = descriptor_->method(i);
        if (!method->options().HasExtension(Battlenet::method_options))
            continue;

        std::map<std::string, std::string> sub_vars;
        sub_vars["classname"] = vars_["classname"];
        sub_vars["name"] = method->name();
        sub_vars["full_name"] = descriptor_->name() + "." + method->name();
        sub_vars["input_type"] = pbcpp::ClassName(method->input_type(), true);
        sub_vars["output_type"] = pbcpp::ClassName(method->output_type(), true);

        if (method->output_type()->name() != "NO_RESPONSE")
        {
            printer->Print(sub_vars, "uint32 $classname$::Handle$name$($input_type$ const* request, $output_type$* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) {\n"
                "  TC_LOG_ERROR(\"service.protobuf\", \"%s Client tried to call not implemented method $full_name$({ %s })\",\n"
                "    GetCallerInfo().c_str(), request->ShortDebugString().c_str());\n"
                "  return ERROR_RPC_NOT_IMPLEMENTED;\n"
                "}\n"
                "\n");
        }
        else
        {
            printer->Print(sub_vars, "uint32 $classname$::Handle$name$($input_type$ const* request) {\n"
                "  TC_LOG_ERROR(\"service.protobuf\", \"%s Client tried to call not implemented method $full_name$({ %s })\",\n"
                "    GetCallerInfo().c_str(), request->ShortDebugString().c_str());\n"
                "  return ERROR_RPC_NOT_IMPLEMENTED;\n"
                "}\n"
                "\n");
        }
    }
}

std::uint32_t BnetServiceGenerator::HashServiceName(std::string const& name)
{
    std::uint32_t hash = 0x811C9DC5;
    for (std::size_t i = 0; i < name.length(); ++i)
    {
        hash ^= name[i];
        hash *= 0x1000193;
    }

    return hash;
}
