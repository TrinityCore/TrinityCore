import os
import shutil
from types import FileType
from jinja2 import Environment, FileSystemLoader
from typedecorator import params, returns
from parser import ClassParser, MethodDoc
import glob
import time


@returns([(str, FileType)])
@params(search_path=str)
def find_class_files(search_path):
    """Find and open all files containing Eluna class methods in `search_path`.

    :param search_path: the path to search for Eluna methods in
    :return: a list of all files containing Eluna methods, and the name of their respective classes
    """
    # Get the current working dir and switch to the search path.
    old_dir = os.getcwd()
    os.chdir(search_path)
    # Search for all files ending in "Methods.h".
    method_file_names = glob.glob('*Methods.h')
    # Open each file.
    method_files = [open(file_name, 'r') for file_name in method_file_names]
    # Go back to where we were before.
    os.chdir(old_dir)
    return method_files


def make_renderer(template_path, link_parser_factory):
    """Return a function that can be used to render Jinja2 templates from the `template_path` directory."""

    # Set up jinja2 environment to load templates from the templates folder.
    env = Environment(loader=FileSystemLoader(template_path), extensions=['jinja2.ext.with_'])


    def inner(template_name, output_path, level, **kwargs):
        env.filters['parse_links'], env.filters['parse_data_type'] = link_parser_factory(level)
        template = env.get_template(template_name)
        static = make_static(level)
        root = make_root(level)
        currdate = time.strftime("%d/%m/%Y")

        with open('build/' + output_path, 'w') as out:
            out.write(template.render(level=level, static=static, root=root, currdate=currdate, **kwargs))

    return inner


def make_static(level):
    return lambda file_name: ('../' * level) + 'static/' + file_name


def make_root(level):
    return lambda file_name: ('../' * level) + file_name


if __name__ == '__main__':
    # Recreate the build folder and copy static files over.
    if os.path.exists('build'):
        shutil.rmtree('build')
    os.mkdir('build')
    shutil.copytree('ElunaDoc/static', 'build/static')

    # Load up all files with methods we need to parse.
    print 'Finding Eluna method files...'
    class_files = find_class_files('../')

    # Parse all the method files.
    classes = []
    for f in class_files:
        print 'Parsing file {}...'.format(f.name)
        classes.append(ClassParser.parse_file(f))
        f.close()

    # Sort the classes so they are in the correct order in lists.
    classes.sort(key=lambda c: c.name)

    def make_parsers(level):
        """Returns a function that parses content for refs to other classes, methods, or enums,
        and automatically inserts the correct link.
        """
        # Make lists of all class names and method names.
        class_names = []
        method_names = []

        for class_ in classes:
            class_names.append('[' + class_.name + ']')

            for method in class_.methods:
                method_names.append('[' + class_.name + ':' + method.name + ']')

        def link_parser(content):
            # Replace all occurrencies of &Class:Function and then &Class with a link to given func or class

            for name in method_names:
                # Take the [] off the front of the method's name.
                full_name = name[1:-1]
                # Split "Class:Method" into "Class" and "Method".
                class_name, method_name = full_name.split(':')
                url = '{}{}/{}.html'.format(('../' * level), class_name, method_name)
                # Replace occurrencies of &Class:Method with the url created
                content = content.replace(name, '<a class="fn" href="{}">{}</a>'.format(url, full_name))

            for name in class_names:
                # Take the [] off the front of the class's name.
                class_name = name[1:-1]
                url = '{}{}/index.html'.format(('../' * level), class_name)
                # Replace occurrencies of &Class:Method with the url created
                content = content.replace(name, '<a class="mod" href="{}">{}</a>'.format(url, class_name))

            return content

        # Links to the "Programming in Lua" documentation for each Lua type.
        lua_type_documentation = {
            'nil': 'http://www.lua.org/pil/2.1.html',
            'boolean': 'http://www.lua.org/pil/2.2.html',
            'number': 'http://www.lua.org/pil/2.3.html',
            'string': 'http://www.lua.org/pil/2.4.html',
            'table': 'http://www.lua.org/pil/2.5.html',
            'function': 'http://www.lua.org/pil/2.6.html',
            '...': 'http://www.lua.org/pil/5.2.html',
        }

        def data_type_parser(content):
            # If the type is a Lua type, return a link to Lua documentation.
            if content in lua_type_documentation:
                url = lua_type_documentation[content]
                return '<strong><a href="{}">{}</a></strong>'.format(url, content)

            # Otherwise try to build a link to the proper page.
            if content in class_names:
                class_name = content[1:-1]
                url = '{}{}/index.html'.format(('../' * level), class_name)
                return '<strong><a class="mod" href="{}">{}</a></strong>'.format(url, class_name)

            # Case for enums to direct to a search on github
            enum_name = content[1:-1]
            url = 'https://github.com/ElunaLuaEngine/ElunaTrinityWotlk/search?l=cpp&q=%22enum+{}%22&type=Code&utf8=%E2%9C%93'.format(enum_name)
            return '<strong><a href="{}">{}</a></strong>'.format(url, enum_name)

            # By default we just return the name without the [] around it
            return content[1:-1]

        return link_parser, data_type_parser

    # Create the render function with the template path and parser maker.
    render = make_renderer('ElunaDoc/templates', make_parsers)

    # Render the index.
    render('index.html', 'index.html', level=0, classes=classes)
    # Render the search index.
    render('search-index.js', 'search-index.js', level=0, classes=classes)

    for class_ in classes:
        print 'Rending pages for class {}...'.format(class_.name)

        # Make a folder for the class.
        os.mkdir('build/' + class_.name)
        index_path = '{}/index.html'.format(class_.name)

        # Render the class's index page.
        render('class.html', index_path, level=1, classes=classes, current_class=class_)

        # Render each method's page.
        for method in class_.methods:
            method_path = '{}/{}.html'.format(class_.name, method.name)
            render('method.html', method_path, level=1, current_class=class_, current_method=method)
