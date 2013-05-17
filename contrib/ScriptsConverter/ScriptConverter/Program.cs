using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace ScriptConverter {
    class Program {
        static void Main(string[] args) {
            if (args.Length != 1) {
                Console.WriteLine("Usage: ScriptsConverter.exe [path_to_dir|path_to_file]");
            } else {
                string path = args[0];
                if (File.Exists(path)) {
                    ProcessFile(path);
                } else if (Directory.Exists(path)) {
                    ProcessDirectory(path);
                } else {
                    Console.WriteLine("Invalid file or directory specified.\r\n\r\nUsage: ScriptsConverter.exe [path_to_dir|path_to_file]");
                }
            }
        }

        static void ProcessDirectory(string path) {
            string[] files = Directory.GetFiles(path, "*.cpp");
            foreach (string file in files) {
                ProcessFile(file);
            }
            string[] dirs = Directory.GetDirectories(path);
            foreach (string dir in dirs) {
                ProcessDirectory(dir);
            }
        }

        class ScriptData {
            public int type = 0;
            public string name;
            public ArrayList methods = new ArrayList();
            public string instanceName = null;
            public string aiName = null;
            public string[] special = new string[] { "GetAI_", "GetInstance_", "GetInstanceData_" };

            public void AddMethod(string method) {
                methods.Add(method);
                int i = 0;
                foreach (string s in special) {
                    ++i;
                    int pos = method.IndexOf(s);
                    if (pos != -1) {
                        type = i;
                        string name = method.Substring(pos + s.Length);
                        if (i == 1) {
                            aiName = name + "AI";
                        }
                        if (i == 2 || i == 3)
                            instanceName = name;
                    }
                }
            }

            public override string ToString() {
                StringBuilder sb = new StringBuilder();
                sb.AppendFormat("Script: {0}\n", name);
                foreach (string method in methods)
                    sb.Append("    ").Append(method).Append("\n");
                sb.Append("\n");
                return sb.ToString();
            }
        }

        static string GetMethod(string method, ref string txt, ref int minPos) {
            string res = null;
            Regex r = new Regex(method + "(\\s|:|[(])");
            Match m = r.Match(txt);
            if (m.Success) {
                int pos = m.Index;
                while (pos-- >= 0 && pos < txt.Length) {
                    if (txt[pos] == '\n') break;
                }
                //pos++;
                int lastPos = txt.IndexOf("\n}", pos);
                if (lastPos != -1) {
                    lastPos += 2;
                    while (lastPos++ >= 0 && lastPos < txt.Length) {
                        if (txt[lastPos] == '\n') break;
                    }
                    res = txt.Substring(pos, lastPos - pos);
                    txt = txt.Remove(pos, lastPos - pos);
                }
                if (pos < minPos)
                    minPos = pos;
            }
            return res;
        }

        static void ProcessFile(string filePath) {
            Console.WriteLine(filePath);

            string txt = File.ReadAllText(filePath);
            string[] lines = File.ReadAllLines(filePath);
            Array.Reverse(lines);

            ArrayList scripts = new ArrayList();
            ScriptData data = null;
            bool scriptStart = false;
            foreach (string line in lines) {
                if (line.IndexOf("Script *") != -1) {
                    break;
                }
                if (line.IndexOf("->RegisterSelf();") != -1) {
                    scriptStart = true;
                    data = new ScriptData();
                    continue;
                }
                if (scriptStart) {
                    if (line.IndexOf("= new Script") != -1) {
                        scriptStart = false;
                        scripts.Add(data);
                        data = null;
                        continue;
                    }
                    Regex r = new Regex("newscript->([a-zA-Z]+) *= *&?([\"_a-zA-Z0-9]+);");
                    Match m = r.Match(line);
                    if (m.Success) {
                        if (m.Groups[1].Value.Equals("Name")) {
                            data.name = m.Groups[2].Value.Trim(new char[] { '"' });
                        } else {
                            data.AddMethod(m.Groups[2].Value);
                        }
                    }
                    continue;
                }
            }
            if (scripts.Count != 0) {
                string register = "";
                foreach (ScriptData sd in scripts) {
                    string ss = "";
                    Console.WriteLine(sd);
                    int minPos = txt.Length;
                    foreach (string method in sd.methods) {
                        string s = GetMethod(method, ref txt, ref minPos);
                        ss += s + "\n";
                    }
                    if (sd.instanceName != null) {
                        string s = GetMethod("struct " + sd.instanceName, ref txt, ref minPos);
                        ss += s + "\n";
                    }
                    if (sd.aiName != null) {
                        string ai = GetMethod("struct " + sd.aiName, ref txt, ref minPos);
                        if (ai != null) {
                            string sm = null;
                            Regex r = new Regex("\\S+ " + sd.aiName + "::([^( ]+)");
                            while (r.IsMatch(txt)) {
                                Match m = r.Match(txt);
                                int startPos = m.Index;
                                int endPos = txt.IndexOf("\n}", startPos);
                                if (endPos != -1)
                                    endPos += 2;
                                while (endPos++ >= 0 && endPos < txt.Length) {
                                    if (txt[endPos] == '\n') break;
                                }
                                sm = txt.Substring(startPos, endPos - startPos);
                                txt = txt.Remove(startPos, endPos - startPos);
                                if (sm != null) {
                                    sm = sm.Replace("\n", "\n    ");
                                    Regex r1 = new Regex("\\S+ " + m.Groups[1] + " *\\([^)]*\\) *;");
                                    Match m1 = r1.Match(ai);
                                    if (m1.Success) {
                                        ai = r1.Replace(ai, sm);
                                    }
                                }
                            }
                            ai = ai.Replace(sd.aiName + "::", "");
                            ss += ai + "\n";
                        }
                    }
                    if (ss.Length != 0) {
                        string typeName = "UnknownScript";
                        switch (sd.type) {
                            case 1: typeName = "CreatureScript"; break;
                            case 2: typeName = "InstanceMapScript"; break;
                            default:
                                if (sd.name.IndexOf("npc") == 0)
                                    typeName = "CreatureScript";
                                else if (sd.name.IndexOf("mob") == 0)
                                    typeName = "CreatureScript";
                                else if (sd.name.IndexOf("boss_") == 0)
                                    typeName = "CreatureScript";
                                else if (sd.name.IndexOf("item_") == 0)
                                    typeName = "ItemScript";
                                else if (sd.name.IndexOf("go_") == 0)
                                    typeName = "GameObjectScript";
                                else if (sd.name.IndexOf("at_") == 0)
                                    typeName = "AreaTriggerScript";
                                else if (sd.name.IndexOf("instance_") == 0)
                                    typeName = "InstanceMapScript";
                                break;
                        }
                        if (sd.instanceName != null)
                            ss = ss.Replace(sd.instanceName, sd.instanceName + "_InstanceMapScript");
                        ss = ss.Replace("\n", "\n    ");
                        ss = "class " + sd.name + " : public " + typeName + "\n{\npublic:\n    " +
                            sd.name + "() : " + typeName + "(\"" + sd.name + "\") { }\n" + ss + "\n};";
                        ss = ss.Replace("_" + sd.name, "");
                        ss = ss.Replace("AIAI", "AI");
                        ss = ss.Replace("    \r\n", "\r\n");
                        ss = ss.Replace("    \n", "\n");
                        txt = txt.Insert(minPos, ss);
                        register = "    new " + sd.name + "();\n" + register;
                    }
                }
                Regex r2 = new Regex("void +AddSC_([_a-zA-Z0-9]+)");
                Match m2 = r2.Match(txt);
                if (m2.Success) {
                    txt = txt.Remove(m2.Index);
                    txt += "void AddSC_" + m2.Groups[1].Value + "()\n{\n" + register + "}\n";
                }
                // File.Copy(filePath, filePath + ".bkp");
                txt = txt.Replace("\r\n", "\n");
                File.WriteAllText(filePath, txt);
            }
        }
    }
}
