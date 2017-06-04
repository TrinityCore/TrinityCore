var searchIndex = {};

{% for class in classes -%}
searchIndex["{{ class.name }}"] = {
    "items": [
        [0, "", "{{ class.name }}", "{{ class.short_description|replace('\n', ' ')|replace('\"', '&#34;')|parse_links|replace('"', '\\"') }}"],
        {%- for method in class.methods %}
        [3, "{{ method.name }}", "", "{{ method.short_description|replace('\n', ' ')|replace('\"', '&#34;')|parse_links|replace('"', '\\"') }}"],
        {%- endfor %}
    ],
    "paths": []
};
{%- endfor %}

initSearch(searchIndex);