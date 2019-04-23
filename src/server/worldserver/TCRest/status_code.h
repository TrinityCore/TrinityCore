#ifndef SIMPLE_WEB_STATUS_CODE_HPP
#define SIMPLE_WEB_STATUS_CODE_HPP

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace SimpleWeb {
  enum class StatusCode {
    unknown = 0,
    information_continue = 100,
    information_switching_protocols,
    information_processing,
    success_ok = 200,
    success_created,
    success_accepted,
    success_non_authoritative_information,
    success_no_content,
    success_reset_content,
    success_partial_content,
    success_multi_status,
    success_already_reported,
    success_im_used = 226,
    redirection_multiple_choices = 300,
    redirection_moved_permanently,
    redirection_found,
    redirection_see_other,
    redirection_not_modified,
    redirection_use_proxy,
    redirection_switch_proxy,
    redirection_temporary_redirect,
    redirection_permanent_redirect,
    client_error_bad_request = 400,
    client_error_unauthorized,
    client_error_payment_required,
    client_error_forbidden,
    client_error_not_found,
    client_error_method_not_allowed,
    client_error_not_acceptable,
    client_error_proxy_authentication_required,
    client_error_request_timeout,
    client_error_conflict,
    client_error_gone,
    client_error_length_required,
    client_error_precondition_failed,
    client_error_payload_too_large,
    client_error_uri_too_long,
    client_error_unsupported_media_type,
    client_error_range_not_satisfiable,
    client_error_expectation_failed,
    client_error_im_a_teapot,
    client_error_misdirection_required = 421,
    client_error_unprocessable_entity,
    client_error_locked,
    client_error_failed_dependency,
    client_error_upgrade_required = 426,
    client_error_precondition_required = 428,
    client_error_too_many_requests,
    client_error_request_header_fields_too_large = 431,
    client_error_unavailable_for_legal_reasons = 451,
    server_error_internal_server_error = 500,
    server_error_not_implemented,
    server_error_bad_gateway,
    server_error_service_unavailable,
    server_error_gateway_timeout,
    server_error_http_version_not_supported,
    server_error_variant_also_negotiates,
    server_error_insufficient_storage,
    server_error_loop_detected,
    server_error_not_extended = 510,
    server_error_network_authentication_required
  };

  inline const std::map<StatusCode, std::string> &status_code_strings() {
    static const std::map<StatusCode, std::string> status_code_strings = {
        {StatusCode::unknown, ""},
        {StatusCode::information_continue, "100 Continue"},
        {StatusCode::information_switching_protocols, "101 Switching Protocols"},
        {StatusCode::information_processing, "102 Processing"},
        {StatusCode::success_ok, "200 OK"},
        {StatusCode::success_created, "201 Created"},
        {StatusCode::success_accepted, "202 Accepted"},
        {StatusCode::success_non_authoritative_information, "203 Non-Authoritative Information"},
        {StatusCode::success_no_content, "204 No Content"},
        {StatusCode::success_reset_content, "205 Reset Content"},
        {StatusCode::success_partial_content, "206 Partial Content"},
        {StatusCode::success_multi_status, "207 Multi-Status"},
        {StatusCode::success_already_reported, "208 Already Reported"},
        {StatusCode::success_im_used, "226 IM Used"},
        {StatusCode::redirection_multiple_choices, "300 Multiple Choices"},
        {StatusCode::redirection_moved_permanently, "301 Moved Permanently"},
        {StatusCode::redirection_found, "302 Found"},
        {StatusCode::redirection_see_other, "303 See Other"},
        {StatusCode::redirection_not_modified, "304 Not Modified"},
        {StatusCode::redirection_use_proxy, "305 Use Proxy"},
        {StatusCode::redirection_switch_proxy, "306 Switch Proxy"},
        {StatusCode::redirection_temporary_redirect, "307 Temporary Redirect"},
        {StatusCode::redirection_permanent_redirect, "308 Permanent Redirect"},
        {StatusCode::client_error_bad_request, "400 Bad Request"},
        {StatusCode::client_error_unauthorized, "401 Unauthorized"},
        {StatusCode::client_error_payment_required, "402 Payment Required"},
        {StatusCode::client_error_forbidden, "403 Forbidden"},
        {StatusCode::client_error_not_found, "404 Not Found"},
        {StatusCode::client_error_method_not_allowed, "405 Method Not Allowed"},
        {StatusCode::client_error_not_acceptable, "406 Not Acceptable"},
        {StatusCode::client_error_proxy_authentication_required, "407 Proxy Authentication Required"},
        {StatusCode::client_error_request_timeout, "408 Request Timeout"},
        {StatusCode::client_error_conflict, "409 Conflict"},
        {StatusCode::client_error_gone, "410 Gone"},
        {StatusCode::client_error_length_required, "411 Length Required"},
        {StatusCode::client_error_precondition_failed, "412 Precondition Failed"},
        {StatusCode::client_error_payload_too_large, "413 Payload Too Large"},
        {StatusCode::client_error_uri_too_long, "414 URI Too Long"},
        {StatusCode::client_error_unsupported_media_type, "415 Unsupported Media Type"},
        {StatusCode::client_error_range_not_satisfiable, "416 Range Not Satisfiable"},
        {StatusCode::client_error_expectation_failed, "417 Expectation Failed"},
        {StatusCode::client_error_im_a_teapot, "418 I'm a teapot"},
        {StatusCode::client_error_misdirection_required, "421 Misdirected Request"},
        {StatusCode::client_error_unprocessable_entity, "422 Unprocessable Entity"},
        {StatusCode::client_error_locked, "423 Locked"},
        {StatusCode::client_error_failed_dependency, "424 Failed Dependency"},
        {StatusCode::client_error_upgrade_required, "426 Upgrade Required"},
        {StatusCode::client_error_precondition_required, "428 Precondition Required"},
        {StatusCode::client_error_too_many_requests, "429 Too Many Requests"},
        {StatusCode::client_error_request_header_fields_too_large, "431 Request Header Fields Too Large"},
        {StatusCode::client_error_unavailable_for_legal_reasons, "451 Unavailable For Legal Reasons"},
        {StatusCode::server_error_internal_server_error, "500 Internal Server Error"},
        {StatusCode::server_error_not_implemented, "501 Not Implemented"},
        {StatusCode::server_error_bad_gateway, "502 Bad Gateway"},
        {StatusCode::server_error_service_unavailable, "503 Service Unavailable"},
        {StatusCode::server_error_gateway_timeout, "504 Gateway Timeout"},
        {StatusCode::server_error_http_version_not_supported, "505 HTTP Version Not Supported"},
        {StatusCode::server_error_variant_also_negotiates, "506 Variant Also Negotiates"},
        {StatusCode::server_error_insufficient_storage, "507 Insufficient Storage"},
        {StatusCode::server_error_loop_detected, "508 Loop Detected"},
        {StatusCode::server_error_not_extended, "510 Not Extended"},
        {StatusCode::server_error_network_authentication_required, "511 Network Authentication Required"}};
    return status_code_strings;
  }

  inline StatusCode status_code(const std::string &status_code_string) noexcept {
    class StringToStatusCode : public std::unordered_map<std::string, SimpleWeb::StatusCode> {
    public:
      StringToStatusCode() {
        for(auto &status_code : status_code_strings())
          emplace(status_code.second, status_code.first);
      }
    };
    static StringToStatusCode string_to_status_code;
    auto pos = string_to_status_code.find(status_code_string);
    if(pos == string_to_status_code.end())
      return StatusCode::unknown;
    return pos->second;
  }

  inline const std::string &status_code(StatusCode status_code_enum) noexcept {
    auto pos = status_code_strings().find(status_code_enum);
    if(pos == status_code_strings().end()) {
      static std::string empty_string;
      return empty_string;
    }
    return pos->second;
  }
} // namespace SimpleWeb

#endif // SIMPLE_WEB_STATUS_CODE_HPP
