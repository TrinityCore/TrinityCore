# Documentation generation
Eluna uses a custom made documentation generator to create it's [web documentation](http://elunaluaengine.github.io/).  
The generator is written in python by Patman. It works by parsing Eluna's source files for comments and then generates the HTML and javascript for the documentation based on them.

This page guides you through generating the web documentation locally and explains the standards of the documentation comments for you to help us improve our documentation. To contribute with your documentation changes, create a [pull request](https://help.github.com/articles/using-pull-requests/)

# Generating locally
- install [python](https://www.python.org/)(2)
  - when installing, tick to install the path variable
  - you may need restart afterwards for the installation to properly take effect
- install a package manager like [pip](https://pip.pypa.io/en/latest/)
  - if you installed pip and it does not work, restart or try easy_install command
- install the dependencies with manager
  - [Jinja2](https://pypi.python.org/pypi/Jinja2)
  - [typedecorator](https://pypi.python.org/pypi/typedecorator)
  - [markdown](https://pypi.python.org/pypi/Markdown)
- Run in cmd `python -m ElunaDoc` when at `\LuaEngine\docs\`

# Documenting
You can document functions in the Eluna source code. To find examples simply open a method header file like `PlayerMethods.h` and see the comments.

## Templates
Here are some basic templates for a function documentation. When defining a parameter or a return value the type and value name are mandatory, unless the parameter type is `...`, which is used for variable arguments; do not include a name in this case.

```c++
/**
 * Short description (about 80 characters long).
 *
 * @param Type paramName
 * @return Type returnName
 */
```

```c++
/**
 * Short description (about 80 characters long).
 *
 * @param Type paramName = defaultValue : parameter description
 * @return Type returnName : return value description
 */
```

This is a template for a function that takes in different parameters. When defining a parameter or a return value, the type and value name are mandatory.

```c++
/**
 * Short description (about 80 characters long).
 *
 * @proto returnValue = (object)
 * @proto returnValue = (x, y, z)
 * @param [WorldObject] object = defaultValue : parameter description
 * @param float x = defaultValue : parameter description
 * @param float y = defaultValue : parameter description
 * @param float z = defaultValue : parameter description
 * @return Type returnName : return value description
 */
```

## Standard
A documentation comment block will always start with `/**` and end with `*/`.
All lines start with `*` character followed by one space before any content.

The first paragrph is used as a short description of the function/class, so it should be kept to about 80 characters. The other paragraphs can be as long as desired.

All paragraphs in the description (including the first) should start with a capital letter and end with a period.
**Paragraphs must be separated by an empty line**, e.g.:

```c++
/**
 * This is a short description (about 80 characters).
 *
 * Here's another paragraph with more info. NOTE THE EMPTY LINE BETWEEN THE PARAGRAPHS.
 * This does need to be short, and this line is still part of the same paragraph because
 * there is no empty line.
 */
 ```

The parameter and return value descriptions should start with a lowercase letter and not end with a period. If more than one sentence is needed, start the *first* without a capital letter and end the *last* without a period.

Any class, enum or function can be referenced (made a link to) with square brackets.
`[Player]` will reference a player. `[WeatherType]` will reference an enum. `[Player:GetName]` will reference a function.

Use correct indentation with documentation comments.

```c++
/**
 * Correct indentation.
 */
```

```c++
/**
* Invalid indentation.
*/
```

## Markdown
You can use [markdown](http://pythonhosted.org//Markdown/) in your descriptions.
For syntax see http://daringfireball.net/projects/markdown/syntax and http://pythonhosted.org//Markdown/#differences

```
/**
 * Description.
 *
 * - list item
 * - list item
 * - list item
 *
 *
 *     // Codeblock
 *     // Code goes here.
 *     // Note the 4-space indent.
 *
 *
 * `code line`
 *
 * *italic*
 * **bold**
 */
```

**The above markdown code produces the output below:**

Description.

- list item
- list item
- list item

```
// Codeblock
// Code goes here.
// Note the 4-space indent.
```

`code line`

*italic*
**bold**

## Types
Here are some examples of possible types and most commonly used ones:

```
string
uint64
uint32
uint16
uint8
int64
int32
int16
int8
double
float
...
[EnumName]
[Player]
[Creature]
[GameObject]
[Item]
[Unit]
[WorldObject]
[Object]
```
