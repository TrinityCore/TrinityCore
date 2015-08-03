/**
 \file XML.h
  
 \author Morgan McGuire
 \maintainer Morgan McGuire
  
 \created 2010-02-11
 \edited  2010-02-24

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
 */

#include "G3D/XML.h"
#include "G3D/fileutils.h"
#include "G3D/TextInput.h"
#include "G3D/TextOutput.h"
#include "G3D/stringutils.h"

namespace G3D {

XML::XML(TextInput& t) : m_type(VALUE) {
    deserialize(t);
}

double XML::number() const {
    return TextInput::parseNumber(m_value);
}


bool XML::boolean() const {
    return TextInput::parseBoolean(m_value);
}


void XML::load(const std::string& filename) {
    TextInput::Settings s;
    s.cppBlockComments = false;
    s.cppLineComments = false;
    s.proofSymbols = false;

    TextInput t(filename, s);
    deserialize(t);
}


void XML::save(const std::string& filename) const {
    std::string s;
    unparse(s);
    writeWholeFile(filename, s);
}

    
void XML::unparse(std::string &s) const {
    TextOutput::Settings set;
    set.wordWrap = TextOutput::Settings::WRAP_WITHOUT_BREAKING;
    TextOutput t(set);

    serialize(t);

    t.commitString(s);
}


void XML::serialize(TextOutput& t) const {
    if (m_type == VALUE) {
        // Raw string; no quotes
        t.writeSymbol(m_value);
    } else {
        t.printf("<%s", m_name.c_str());
        for (AttributeTable::Iterator it = m_attribute.begin(); it.isValid(); ++it) {
            t.printf(" %s=\"%s\"", it->key.c_str(), it->value.m_value.c_str());
        }
        t.printf(">");
        t.writeNewline();
        t.pushIndent();
        for (int i = 0; i < m_child.size(); ++i) {
            m_child[i].serialize(t);
            if (m_child[i].m_type == VALUE) {
                // Only tags know to append a newline
                t.writeNewline();
            }
        }
        t.popIndent();
        t.printf("</%s>", m_name.c_str());
        t.writeNewline();
    }
}


void XML::parse(const std::string& s) {
    TextInput t(TextInput::FROM_STRING, s);
    deserialize(t);
}


/** True if the next token begins the close tag */
static bool atClose(TextInput& t, const std::string name) {
    if ((t.peek().type() == Token::SYMBOL) && (t.peek().string() == "<")) {
        // Need to keep looking ahead
        Token p0 = t.read();
        if ((t.peek().type() == Token::SYMBOL) && (t.peek().string() == "/")) {
            // Check the name on the close tag.  It *must* match if
            // this is a well-formed document, but there might be a
            // tag error.
            Token p1 = t.read();
            Token p2 = t.peek();
            std::string s = p2.string();
            debugAssertM(beginsWith(name, s), "Mismatched close tag");

            // Put the tokens back
            t.push(p1);
            t.push(p0);
            return true;
        } else {
            // Put the read token back
            t.push(p0);
            return false;
        }
    } else {
        return false;
    }
}

void XML::deserialize(TextInput& t) {
 begin:
    Token n = t.read();
    m_attribute.clear();
    m_child.clear();
    m_name = "";
    m_value = "";

    if ((n.type() == Token::SYMBOL) && (n.string() == "<")) {
        // Beginning a tag
        
        // Read name
        n = t.read();
        debugAssert(n.type() == Token::SYMBOL);
        bool isComment = 
            (n.string() == "!") && 
            (t.peek().type() == Token::SYMBOL) &&
            (t.peek().string() == "--");

        // ignored tag:        <?xml> or <!xml>
        // comment tag:        <!--   ... -->

        if ((n.string() == "?") || ((n.string() == "!") && ! isComment)) {
            // Ignore this tag
            while (t.hasMore() && ! ((n.type() == Token::SYMBOL) && (n.string() == ">"))) {
                n = t.read();
            }
            goto begin;
        } else if (isComment) {
            // Ignore until "-->"
            bool prevWasDash = false;
            while (t.hasMore() && ! ((n.type() == Token::SYMBOL) && (n.string() == ">") && prevWasDash)) {
                prevWasDash = (n.type() == Token::SYMBOL) && (n.string() == "--");
                n = t.read();
            }
            goto begin;
        }

        // Keep reading until no colon
        m_name += n.string();
        n = t.read();
        while ((n.type() == Token::SYMBOL) && (n.string() == ":")) {
            //  tag with namespace: <x:y>
            m_name += ":" + t.readSymbol();
            n = t.read();
        }
        
        // Read end of tag/close
        bool done = false;
        while (! done) {
            debugAssert(n.type() == Token::SYMBOL);
            if (n.string() == "/") {
                // empty-element tag:  <foo/>
                // Consume the close tag
                t.readSymbol(">");
                done = true;

            } else if (n.string() == ">") {
                // End of open tag: read children until close tag
                while (! atClose(t, m_name)) {
                    m_child.next().deserialize(t);
                }

                // Read close tag (we wouldn't be here unless it parses correctly)
                while (t.hasMore() && ! (t.readSymbol() == ">")) {}
                
                done = true;
            } else {
                // Attribute pair
                std::string k = n.string();
                t.readSymbol("=");
                std::string v = t.read().string();
                m_attribute.set(k, v);

                // Advance to next
                n = t.read();
            }
        }
    } else {
        // Beginning embedded content.  Read until the end of file or the next tag.
        m_type = VALUE;
        m_value += n.string();

        n = t.peek();
        while (t.hasMore() && ! ((n.type() == Token::SYMBOL) && (n.string() == "<"))) {
            m_value += " " + t.read().string();
            n = t.peek();
        }
    }
}

}
