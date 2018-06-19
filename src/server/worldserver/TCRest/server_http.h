#ifndef SERVER_HTTP_HPP
#define SERVER_HTTP_HPP

#include "utility.h"
#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <thread>

#ifdef USE_STANDALONE_ASIO
#include <asio.hpp>
namespace SimpleWeb {
  using error_code = std::error_code;
  using errc = std::errc;
  namespace make_error_code = std;
} // namespace SimpleWeb
#else
#include <boost/asio.hpp>
namespace SimpleWeb {
  namespace asio = boost::asio;
  using error_code = boost::system::error_code;
  namespace errc = boost::system::errc;
  namespace make_error_code = boost::system::errc;
} // namespace SimpleWeb
#endif

// Late 2017 TODO: remove the following checks and always use std::regex
#ifdef USE_BOOST_REGEX
#include <boost/regex.hpp>
namespace SimpleWeb {
  namespace regex = boost;
}
#else
#include <regex>
namespace SimpleWeb {
  namespace regex = std;
}
#endif

namespace SimpleWeb {
  template <class socket_type>
  class Server;

  template <class socket_type>
  class ServerBase {
  public:
    virtual ~ServerBase() {}

    class Response : public std::ostream {
      friend class ServerBase<socket_type>;

      asio::streambuf streambuf;

      std::shared_ptr<socket_type> socket;

      Response(const std::shared_ptr<socket_type> &socket) : std::ostream(&streambuf), socket(socket) {}

      template <class size_type>
      void write_header(const CaseInsensitiveMultimap &header, size_type size) {
        bool content_length_written = false;
        bool chunked_transfer_encoding = false;
        for(auto &field : header) {
          if(!content_length_written && case_insensitive_equal(field.first, "content-length"))
            content_length_written = true;
          else if(!chunked_transfer_encoding && case_insensitive_equal(field.first, "transfer-encoding") && case_insensitive_equal(field.second, "chunked"))
            chunked_transfer_encoding = true;

          *this << field.first << ": " << field.second << "\r\n";
        }
        if(!content_length_written && !chunked_transfer_encoding && !close_connection_after_response)
          *this << "Content-Length: " << size << "\r\n\r\n";
        else
          *this << "\r\n";
      }

    public:
      size_t size() {
        return streambuf.size();
      }

      /// Write directly to stream buffer using std::ostream::write
      void write(const char_type *ptr, std::streamsize n) {
        std::ostream::write(ptr, n);
      }

      /// Convenience function for writing status line, potential header fields, and empty content
      void write(StatusCode status_code = StatusCode::success_ok, const CaseInsensitiveMultimap &header = CaseInsensitiveMultimap()) {
        *this << "HTTP/1.1 " << SimpleWeb::status_code(status_code) << "\r\n";
        write_header(header, 0);
      }

      /// Convenience function for writing status line, header fields, and content
      void write(StatusCode status_code, const std::string &content, const CaseInsensitiveMultimap &header = CaseInsensitiveMultimap()) {
        *this << "HTTP/1.1 " << SimpleWeb::status_code(status_code) << "\r\n";
        write_header(header, content.size());
        if(!content.empty())
          *this << content;
      }

      /// Convenience function for writing status line, header fields, and content
      void write(StatusCode status_code, std::istream &content, const CaseInsensitiveMultimap &header = CaseInsensitiveMultimap()) {
        *this << "HTTP/1.1 " << SimpleWeb::status_code(status_code) << "\r\n";
        content.seekg(0, std::ios::end);
        auto size = content.tellg();
        content.seekg(0, std::ios::beg);
        write_header(header, size);
        if(size)
          *this << content.rdbuf();
      }

      /// Convenience function for writing success status line, header fields, and content
      void write(const std::string &content, const CaseInsensitiveMultimap &header = CaseInsensitiveMultimap()) {
        write(StatusCode::success_ok, content, header);
      }

      /// Convenience function for writing success status line, header fields, and content
      void write(std::istream &content, const CaseInsensitiveMultimap &header = CaseInsensitiveMultimap()) {
        write(StatusCode::success_ok, content, header);
      }

      /// Convenience function for writing success status line, and header fields
      void write(const CaseInsensitiveMultimap &header) {
        write(StatusCode::success_ok, std::string(), header);
      }

      /// If true, force server to close the connection after the response have been sent.
      ///
      /// This is useful when implementing a HTTP/1.0-server sending content
      /// without specifying the content length.
      bool close_connection_after_response = false;
    };

    class Content : public std::istream {
      friend class ServerBase<socket_type>;

    public:
      size_t size() {
        return streambuf.size();
      }
      /// Convenience function to return std::string. Note that the stream buffer is emptied when this functions is used.
      std::string string() {
        std::stringstream ss;
        ss << rdbuf();
        return ss.str();
      }

    private:
      asio::streambuf &streambuf;
      Content(asio::streambuf &streambuf) : std::istream(&streambuf), streambuf(streambuf) {}
    };

    class Request {
      friend class ServerBase<socket_type>;
      friend class Server<socket_type>;

    public:
      std::string method, path, http_version;

      Content content;

      CaseInsensitiveMultimap header;

      regex::smatch path_match;

      std::string remote_endpoint_address;
      unsigned short remote_endpoint_port;

      /// Returns query keys with percent-decoded values.
      CaseInsensitiveMultimap parse_query_string() {
        auto pos = path.find('?');
        if(pos != std::string::npos && pos + 1 < path.size())
          return SimpleWeb::QueryString::parse(path.substr(pos + 1));
        else
          return CaseInsensitiveMultimap();
      }

    private:
      Request(const socket_type &socket) : content(streambuf) {
        try {
          remote_endpoint_address = socket.lowest_layer().remote_endpoint().address().to_string();
          remote_endpoint_port = socket.lowest_layer().remote_endpoint().port();
        }
        catch(...) {
        }
      }

      asio::streambuf streambuf;
    };

    class Config {
      friend class ServerBase<socket_type>;

      Config(unsigned short port) : port(port) {}

    public:
      /// Port number to use. Defaults to 80 for HTTP and 443 for HTTPS.
      unsigned short port;
      /// If io_service is not set, number of threads that the server will use when start() is called.
      /// Defaults to 1 thread.
      size_t thread_pool_size = 1;
      /// Timeout on request handling. Defaults to 5 seconds.
      size_t timeout_request = 5;
      /// Timeout on content handling. Defaults to 300 seconds.
      size_t timeout_content = 300;
      /// IPv4 address in dotted decimal form or IPv6 address in hexadecimal notation.
      /// If empty, the address will be any address.
      std::string address;
      /// Set to false to avoid binding the socket to an address that is already in use. Defaults to true.
      bool reuse_address = true;
    };
    ///Set before calling start().
    Config config;

  private:
    class regex_orderable : public regex::regex {
      std::string str;

    public:
      regex_orderable(const char *regex_cstr) : regex::regex(regex_cstr), str(regex_cstr) {}
      regex_orderable(const std::string &regex_str) : regex::regex(regex_str), str(regex_str) {}
      bool operator<(const regex_orderable &rhs) const {
        return str < rhs.str;
      }
    };

  public:
    /// Warning: do not add or remove resources after start() is called
    std::map<regex_orderable, std::map<std::string, std::function<void(std::shared_ptr<typename ServerBase<socket_type>::Response>, std::shared_ptr<typename ServerBase<socket_type>::Request>)>>> resource;

    std::map<std::string, std::function<void(std::shared_ptr<typename ServerBase<socket_type>::Response>, std::shared_ptr<typename ServerBase<socket_type>::Request>)>> default_resource;

    std::function<void(std::shared_ptr<typename ServerBase<socket_type>::Request>, const error_code &)> on_error;

    std::function<void(std::shared_ptr<socket_type> socket, std::shared_ptr<typename ServerBase<socket_type>::Request>)> on_upgrade;

    virtual void start() {
      if(!io_service) {
        io_service = std::make_shared<asio::io_service>();
        internal_io_service = true;
      }

      if(io_service->stopped())
        io_service->reset();

      asio::ip::tcp::endpoint endpoint;
      if(config.address.size() > 0)
        endpoint = asio::ip::tcp::endpoint(asio::ip::address::from_string(config.address), config.port);
      else
        endpoint = asio::ip::tcp::endpoint(asio::ip::tcp::v4(), config.port);

      if(!acceptor)
        acceptor = std::unique_ptr<asio::ip::tcp::acceptor>(new asio::ip::tcp::acceptor(*io_service));
      acceptor->open(endpoint.protocol());
      acceptor->set_option(asio::socket_base::reuse_address(config.reuse_address));
      acceptor->bind(endpoint);
      acceptor->listen();

      accept();

      if(internal_io_service) {
        //If thread_pool_size>1, start m_io_service.run() in (thread_pool_size-1) threads for thread-pooling
        threads.clear();
        for(size_t c = 1; c < config.thread_pool_size; c++) {
          threads.emplace_back([this]() {
            io_service->run();
          });
        }

        //Main thread
        if(config.thread_pool_size > 0)
          io_service->run();

        //Wait for the rest of the threads, if any, to finish as well
        for(auto &t : threads) {
          t.join();
        }
      }
    }

    void stop() {
      acceptor->close();
      if(internal_io_service)
        io_service->stop();
    }

    ///Use this function if you need to recursively send parts of a longer message
    void send(const std::shared_ptr<Response> &response, const std::function<void(const error_code &)> &callback = nullptr) const {
      asio::async_write(*response->socket, response->streambuf, [callback](const error_code &ec, size_t /*bytes_transferred*/) {
        if(callback)
          callback(ec);
      });
    }

    /// If you have your own asio::io_service, store its pointer here before running start().
    std::shared_ptr<asio::io_service> io_service;

  protected:
    bool internal_io_service = false;

    std::unique_ptr<asio::ip::tcp::acceptor> acceptor;
    std::vector<std::thread> threads;

    ServerBase(unsigned short port) : config(port) {}

    virtual void accept() = 0;

    std::shared_ptr<asio::deadline_timer> get_timeout_timer(const std::shared_ptr<socket_type> &socket, long seconds) {
      if(seconds == 0)
        return nullptr;

      auto timer = std::make_shared<asio::deadline_timer>(*io_service);
      timer->expires_from_now(boost::posix_time::seconds(seconds));
      timer->async_wait([socket](const error_code &ec) {
        if(!ec) {
          error_code ec;
          socket->lowest_layer().shutdown(asio::ip::tcp::socket::shutdown_both, ec);
          socket->lowest_layer().close();
        }
      });
      return timer;
    }

    void read_request_and_content(const std::shared_ptr<socket_type> &socket) {
      //Create new streambuf (Request::streambuf) for async_read_until()
      //shared_ptr is used to pass temporary objects to the asynchronous functions
      std::shared_ptr<Request> request(new Request(*socket));

      //Set timeout on the following asio::async-read or write function
      auto timer = this->get_timeout_timer(socket, config.timeout_request);

      asio::async_read_until(*socket, request->streambuf, "\r\n\r\n", [this, socket, request, timer](const error_code &ec, size_t bytes_transferred) {
        if(timer)
          timer->cancel();
        if(!ec) {
          //request->streambuf.size() is not necessarily the same as bytes_transferred, from Boost-docs:
          //"After a successful async_read_until operation, the streambuf may contain additional data beyond the delimiter"
          //The chosen solution is to extract lines from the stream directly when parsing the header. What is left of the
          //streambuf (maybe some bytes of the content) is appended to in the async_read-function below (for retrieving content).
          size_t num_additional_bytes = request->streambuf.size() - bytes_transferred;

          if(!this->parse_request(request))
            return;

          //If content, read that as well
          auto it = request->header.find("Content-Length");
          if(it != request->header.end()) {
            unsigned long long content_length;
            try {
              content_length = stoull(it->second);
            }
            catch(const std::exception &/*e*/) {
              if(on_error)
                on_error(request, make_error_code::make_error_code(errc::protocol_error));
              return;
            }
            if(content_length > num_additional_bytes) {
              //Set timeout on the following asio::async-read or write function
              auto timer = this->get_timeout_timer(socket, config.timeout_content);
              asio::async_read(*socket, request->streambuf, asio::transfer_exactly(content_length - num_additional_bytes), [this, socket, request, timer](const error_code &ec, size_t /*bytes_transferred*/) {
                if(timer)
                  timer->cancel();
                if(!ec)
                  this->find_resource(socket, request);
                else if(on_error)
                  on_error(request, ec);
              });
            }
            else
              this->find_resource(socket, request);
          }
          else
            this->find_resource(socket, request);
        }
        else if(on_error)
          on_error(request, ec);
      });
    }

    bool parse_request(const std::shared_ptr<Request> &request) const {
      std::string line;
      getline(request->content, line);
      size_t method_end;
      if((method_end = line.find(' ')) != std::string::npos) {
        size_t path_end;
        if((path_end = line.find(' ', method_end + 1)) != std::string::npos) {
          request->method = line.substr(0, method_end);
          request->path = line.substr(method_end + 1, path_end - method_end - 1);

          size_t protocol_end;
          if((protocol_end = line.find('/', path_end + 1)) != std::string::npos) {
            if(line.compare(path_end + 1, protocol_end - path_end - 1, "HTTP") != 0)
              return false;
            request->http_version = line.substr(protocol_end + 1, line.size() - protocol_end - 2);
          }
          else
            return false;

          getline(request->content, line);
          size_t param_end;
          while((param_end = line.find(':')) != std::string::npos) {
            size_t value_start = param_end + 1;
            if((value_start) < line.size()) {
              if(line[value_start] == ' ')
                value_start++;
              if(value_start < line.size())
                request->header.emplace(line.substr(0, param_end), line.substr(value_start, line.size() - value_start - 1));
            }

            getline(request->content, line);
          }
        }
        else
          return false;
      }
      else
        return false;
      return true;
    }

    void find_resource(const std::shared_ptr<socket_type> &socket, const std::shared_ptr<Request> &request) {
      //Upgrade connection
      if(on_upgrade) {
        auto it = request->header.find("Upgrade");
        if(it != request->header.end()) {
          on_upgrade(socket, request);
          return;
        }
      }
      //Find path- and method-match, and call write_response
      for(auto &regex_method : resource) {
        auto it = regex_method.second.find(request->method);
        if(it != regex_method.second.end()) {
          regex::smatch sm_res;
          if(regex::regex_match(request->path, sm_res, regex_method.first)) {
            request->path_match = std::move(sm_res);
            write_response(socket, request, it->second);
            return;
          }
        }
      }
      auto it = default_resource.find(request->method);
      if(it != default_resource.end()) {
        write_response(socket, request, it->second);
      }
    }

    void write_response(const std::shared_ptr<socket_type> &socket, const std::shared_ptr<Request> &request,
                        std::function<void(std::shared_ptr<typename ServerBase<socket_type>::Response>, std::shared_ptr<typename ServerBase<socket_type>::Request>)> &resource_function) {
      //Set timeout on the following asio::async-read or write function
      auto timer = this->get_timeout_timer(socket, config.timeout_content);

      auto response = std::shared_ptr<Response>(new Response(socket), [this, request, timer](Response *response_ptr) {
        auto response = std::shared_ptr<Response>(response_ptr);
        this->send(response, [this, response, request, timer](const error_code &ec) {
          if(timer)
            timer->cancel();
          if(!ec) {
            if(response->close_connection_after_response)
              return;

            auto range = request->header.equal_range("Connection");
            for(auto it = range.first; it != range.second; it++) {
              if(case_insensitive_equal(it->second, "close")) {
                return;
              }
              else if(case_insensitive_equal(it->second, "keep-alive")) {
                this->read_request_and_content(response->socket);
                return;
              }
            }
            if(request->http_version >= "1.1")
              this->read_request_and_content(response->socket);
          }
          else if(on_error)
            on_error(request, ec);
        });
      });

      try {
        resource_function(response, request);
      }
      catch(const std::exception &/*e*/) {
        if(on_error)
          on_error(request, make_error_code::make_error_code(errc::operation_canceled));
        return;
      }
    }
  };

  template <class socket_type>
  class Server : public ServerBase<socket_type> {};

  typedef asio::ip::tcp::socket HTTP;

  template <>
  class Server<HTTP> : public ServerBase<HTTP> {
  public:
    DEPRECATED Server(unsigned short port, size_t thread_pool_size = 1, long timeout_request = 5, long timeout_content = 300) : Server() {
      config.port = port;
      config.thread_pool_size = thread_pool_size;
      config.timeout_request = timeout_request;
      config.timeout_content = timeout_content;
    }

    Server() : ServerBase<HTTP>::ServerBase(80) {}

  protected:
    void accept() {
      //Create new socket for this connection
      //Shared_ptr is used to pass temporary objects to the asynchronous functions
      auto socket = std::make_shared<HTTP>(*io_service);

      acceptor->async_accept(*socket, [this, socket](const error_code &ec) {
        //Immediately start accepting a new connection (if io_service hasn't been stopped)
        if(ec != asio::error::operation_aborted)
          accept();

        if(!ec) {
          asio::ip::tcp::no_delay option(true);
          socket->set_option(option);

          this->read_request_and_content(socket);
        }
        else if(on_error)
          on_error(std::shared_ptr<Request>(new Request(*socket)), ec);
      });
    }
  };
} // namespace SimpleWeb

#endif /* SERVER_HTTP_HPP */
