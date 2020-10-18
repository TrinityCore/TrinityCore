import re
from types import FileType
import markdown
from typedecorator import params, returns, Nullable


class ParameterDoc(object):
    """The documentation data of a parameter or return value for an Eluna method."""

    # The integer ranges that each C++ type is valid for. None means valid for all numbers.
    valid_ranges = {
        'float': None,
        'double': None,
        'int': ('-2,147,483,647', '2,147,483,647'),  # This should be -32767..32767, but it's pretty safe to assume 32-bit.
        'int8': ('-127', '127'),
        'uint8': ('0', '255'),
        'int16': ('-32,767', '32,767'),
        'uint16': ('0', '65,535'),
        'int32': ('-2,147,483,647', '2,147,483,647'),
        'uint32': ('0', '4,294,967,295'),
        'int64': ('-9,223,372,036,854,775,808', '9,223,372,036,854,775,807'),
        'uint64': ('0', '18,446,744,073,709,551,615'),
    }

    @params(self=object, name=Nullable(unicode), data_type=str, description=unicode, default_value=Nullable(unicode))
    def __init__(self, name, data_type, description, default_value=None):
        """If `name` is not provided, the Parameter is a returned value instead of a parameter."""
        self.name = name
        self.data_type = data_type
        self.default_value = default_value

        if self.data_type == '...':
            self.name = '...'
        else:
            assert(self.name is not None)

        if description:
            # Capitalize the first letter, add a period, and parse as Markdown.
            self.description = '{}{}. '.format(description[0].capitalize(), description[1:])
            self.description = markdown.markdown(self.description)
        else:
            self.description = ''

        # If the data type is a C++ number, convert to Lua number and add range info to description.
        if self.data_type in ['float', 'double', 'int', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32']:
            range = ParameterDoc.valid_ranges[self.data_type]
            if range:
                self.description += '<p><em>Valid numbers</em>: integers from {0} to {1}.</p>'.format(range[0], range[1])
            else:
                self.description += '<p><em>Valid numbers</em>: all decimal numbers.</p>'

            self.data_type = 'number'

        elif self.data_type == 'bool':
            self.data_type = 'boolean'

        elif self.data_type == 'int64' or self.data_type == 'uint64':
            self.data_type = '[' + self.data_type + ']'

        elif not self.data_type in ['nil', 'boolean', 'number', 'string', 'table', 'function', '...'] and self.data_type[:1] != '[':
            print "Missing [] from data type `" + self.data_type + "`"


class MethodDoc(object):
    """The documentation data of an Eluna method."""
    @params(self=object, name=unicode, description=unicode, prototypes=[unicode], parameters=[ParameterDoc], returned=[ParameterDoc])
    def __init__(self, name, description, prototypes, parameters, returned):
        self.name = name
        self.prototypes = prototypes
        self.parameters = parameters
        self.returned = returned

        # Parse the description as Markdown.
        self.description = markdown.markdown(description)
        # Pull the first paragraph out of the description as the short description.
        self.short_description = self.description.split('</p>')[0][3:]
        # If it has a description, it is "documented".
        self.documented = self.description != ''


class MangosClassDoc(object):
    """The documentation of a MaNGOS class that has Lua methods."""
    @params(self=object, name=unicode, description=unicode, methods=[MethodDoc])
    def __init__(self, name, description, methods):
        self.name = name
        # Parse the description as Markdown.
        self.description = markdown.markdown(description)
        # Pull the first paragraph out of the description as the short description.
        self.short_description = self.description.split('</p>')[0][3:]
        # Sort the methods by their names.
        self.methods = sorted(methods, key=lambda m: m.name)

        # If any of our methods are not documented, we aren't fully documented.
        for method in methods:
            if not method.documented:
                self.fully_documented = False
                break
        else:
            self.fully_documented = True

        # In the same vein, if any of our methods are documented, we aren't fully *un*documented.
        for method in methods:
            if method.documented:
                self.fully_undocumented = False
                break
        else:
            self.fully_undocumented = True


class ClassParser(object):
    """Parses a file line-by-line and returns methods when enough information is received to build them."""

    # Various regular expressions to parse different parts of the doc string.
    # There are used to parse the class's description.
    class_start_regex = re.compile(r"\s*/\*\*\*")  # The start of class documentation, i.e. /***
    class_body_regex = re.compile(r"\s*\*\s*(.*)")  # The "body", i.e. a * and optionally some descriptive text.
    class_end_regex = re.compile(r"\s*\*/")  # The end of the comment portion, i.e. */

    # These are used to parse method documentation.
    start_regex = re.compile(r"\s*/\*\*")  # The start of documentation, i.e. /**
    body_regex = re.compile(r"\s*\s?\*\s?(.*)")  # The "body", i.e. a * and optionally some descriptive text.
    # An extra optional space (\s?) was thrown in to make it different from `class_body_regex`.

    param_regex = re.compile(r"""\s*\*\s@param\s    # The @param tag starts with opt. whitespace followed by "* @param ".
                                 ([^\s]+)\s(\w+)?   # The data type, a space, and the name of the param.
                                 (?:\s=\s(\w+))?    # The default value: a = surrounded by spaces, followed by text.
                                 (?:\s:\s(.+))?     # The description: a colon surrounded by spaces, followed by text.
                                 """, re.X)
    # This is the same as the @param tag, minus the default value part.
    return_regex = re.compile(r"""\s*\*\s@return\s
                                  ([\[\]\w]+)\s(\w+)
                                  (?:\s:\s(.+))?
                                  """, re.X)
    proto_regex = re.compile(r"""\s*\*\s@proto\s
                                 ([\w\s,]+)?          # The list of arguments.
                                 (?:=\s)?             # An equals sign and a space separate the args and returns.
                                 (?:\(([\w\s,]+)\))?  # The list of return values, in parens.
                                 """, re.X)

    comment_end_regex = re.compile(r"\s*\*/")  # The end of the comment portion, i.e. */
    end_regex = re.compile(r"\s*int\s(\w+)\s*\(")  # The end of the documentation, i.e. int MethodName(

    def __init__(self, class_name):
        assert ClassParser.class_body_regex is not ClassParser.body_regex
        # The methods that have been parsed.
        self.methods = []
        # The name of the class being parsed.
        self.class_name = class_name
        # The description of the class being parsed.
        self.class_description = ''
        # Reset the parser's state machine.
        self.reset()

    def reset(self):
        # What the last handled regex was, to determine what the next should be.
        self.last_regex = None

        # These are used to piece together the next `Method`.
        self.description = ''
        self.params = []
        self.returned = []
        self.method_name = None
        self.prototypes = []

    def handle_class_body(self, match):
        text = match.group(1)
        self.class_description += text + '\n'

    def handle_body(self, match):
        text = match.group(1)
        self.description += text + '\n'

    def handle_param(self, match):
        data_type, name, default, description = match.group(1), match.group(2), match.group(3), match.group(4)
        self.params.append(ParameterDoc(name, data_type, description, default))

    def handle_return(self, match):
        data_type, name, description = match.group(1), match.group(2), match.group(3)
        self.returned.append(ParameterDoc(name, data_type, description))

    def handle_proto(self, match):
        return_values, parameters = match.group(1), match.group(2)
        parameters = ' '+parameters+' ' if parameters else ''
        return_values = return_values + '= ' if return_values else ''

        if self.class_name == 'Global':
            prototype = '{0}{{0}}({1})'.format(return_values, parameters)
        else:
            prototype = '{0}{1}:{{0}}({2})'.format(return_values, self.class_name, parameters)

        self.prototypes.append(prototype)

    def handle_end(self, match):
        self.method_name = match.group(1)

        def make_prototype(parameters):
            if parameters != '':
                parameters = ' ' + parameters + ' '

            if self.class_name == 'Global':
                if self.returned:
                    return_values = ', '.join([param.name for param in self.returned])
                    prototype = '{0} = {1}({2})'.format(return_values, self.method_name, parameters)
                else:
                    prototype = '{0}({1})'.format(self.method_name, parameters)
            else:
                if self.returned:
                    return_values = ', '.join([param.name for param in self.returned])
                    prototype = '{0} = {1}:{2}({3})'.format(return_values, self.class_name, self.method_name, parameters)
                else:
                    prototype = '{0}:{1}({2})'.format(self.class_name, self.method_name, parameters)

            return prototype

        # If there's no prototype, make one with all params and returns.
        if not self.prototypes:
            # A list of all parameters with default values.
            params_with_default = []
            # The index of the last non-default parameter.
            last_non_default_i = 0
            # If False, a parameter WITHOUT a default value follows one WITH a default value.
            # In this case, don't bother generating prototypes.
            simple_order = True

            for i, param in enumerate(self.params):
                if param.default_value:
                    params_with_default.append(param)
                else:
                    last_non_default_i = i
                    if params_with_default:
                        simple_order = False

            if not params_with_default or not simple_order:
                # Just generate one prototype with all the parameters.
                parameters = ', '.join([param.name for param in self.params])
                self.prototypes.append(make_prototype(parameters))
            else:
                # Generate a prototype for all the non-default parameters,
                #   then one for each default parameter with all the previous parameters.
                for i in range(last_non_default_i, len(self.params)):
                    parameters = ', '.join([param.name for param in self.params[:i+1]])
                    self.prototypes.append(make_prototype(parameters))

        else:
            # Format the method name into each prototype.
            self.prototypes = [proto.format(self.method_name) for proto in self.prototypes]

        self.methods.append(MethodDoc(self.method_name, self.description, self.prototypes, self.params, self.returned))

    # Table of which handler is used to handle each regular expressions.
    regex_handlers = {
        class_start_regex: None,
        class_body_regex: handle_class_body,
        class_end_regex: None,
        start_regex: None,
        body_regex: handle_body,
        param_regex: handle_param,
        return_regex: handle_return,
        proto_regex: handle_proto,
        comment_end_regex: None,
        end_regex: handle_end,
    }

    # Table of which regular expressions can follow the last handled regex.
    # `body_regex` must always come LAST when used, since it also matches param, return, and comment_end.
    next_regexes = {
        None: [class_start_regex, start_regex, end_regex],
        class_start_regex: [class_end_regex, class_body_regex],
        class_body_regex: [class_end_regex, class_body_regex],
        class_end_regex: [],
        start_regex: [param_regex, return_regex, proto_regex, comment_end_regex, body_regex],
        body_regex: [param_regex, return_regex, proto_regex, comment_end_regex, body_regex],
        proto_regex: [param_regex, return_regex, proto_regex, comment_end_regex, body_regex],
        param_regex: [param_regex, return_regex, comment_end_regex, body_regex],
        return_regex: [return_regex, comment_end_regex],
        comment_end_regex: [end_regex],
        end_regex: [],
    }

    @returns(Nullable(MethodDoc))
    @params(self=object, line=str)
    def next_line(self, line):
        """Parse the next line of the file.

        This method returns a `Method` when enough data to form a `Method` has been parsed.
        Otherwise, it returns None.
        """
        # Get the list of expected regular expressions using the last one handled.
        valid_regexes = self.next_regexes[self.last_regex]

        # Try to find a match.
        for regex in valid_regexes:
            match = regex.match(line)

            if match:
                handler = self.regex_handlers[regex]

                if handler:
                    handler(self, match)

                # Not every regex has a handler, but keep track of where we are anyway.
                self.last_regex = regex
                # Break at the first match.
                break
        else:
            # No valid regex was found, reset everything.
            self.reset()

    @returns(MangosClassDoc)
    def to_class_doc(self):
        """Create an instance of `MangosClassDoc` from the parser's data.

        Is called by `parse_file` once parsing is finished.
        """
        return MangosClassDoc(self.class_name, self.class_description, self.methods)

    @staticmethod
    @returns(MangosClassDoc)
    @params(file=FileType)
    def parse_file(file):
        """Parse the file `file` into a documented class."""
        # Get the class name from "ClassMethods.h" by stripping off "Methods.h".
        class_name = file.name[:-len('Methods.h')]
        parser = ClassParser(class_name)

        line = file.readline()

        while line:
            parser.next_line(line)
            line = file.readline()

        return parser.to_class_doc()
