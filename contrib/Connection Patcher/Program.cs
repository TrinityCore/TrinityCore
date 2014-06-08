/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

using Connection_Patcher.Constants;
using System;
using System.IO;
using System.Net;
using System.Text;
using System.Threading;

namespace Connection_Patcher
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length >= 1)
            {
                Console.ForegroundColor = ConsoleColor.Cyan;

                Console.WriteLine("Client Connection Patcher");
                Console.WriteLine("Press Enter to patch...");

                Console.ReadKey(true);

                var commonAppData = Environment.GetFolderPath(Environment.SpecialFolder.CommonApplicationData);
                var modulePath    = "";
                var moduleFile    = "";

                // Let's use Win32 as default module
                var patchSend         = Patches.Windows.x86.Send;
                var offsetSend        = Offsets.Windows.x86.Send;
                var patchRecv         = Patches.Windows.x86.Recv;
                var offsetRecv        = Offsets.Windows.x86.Recv;
                var patchBNet         = Patches.Windows.x86.BNet;
                var offsetBNet        = Offsets.Windows.x86.BNet;
                var patchSignature    = Patches.Windows.x86.Signature;
                var offsetSignature   = Offsets.Windows.x86.Signature;
                var fileName          = args[0].Replace(".exe", "_Patched.exe");
                var battleNetFileName = args[0].Replace("Wow.exe", "Battle.net.dll");
                var modulePatch       = Patches.Windows.x86.Password;
                var modulePattern     = Patterns.Windows.x86.Password;
                var realmListPatch    = Patches.Windows.x86.RealmList;
                var realmListoffset   = Offsets.Windows.x86.RealmList;
                var realmListBnPatch  = Patches.Windows.x86.RealmListBn;
                var realmListBnPattern = Patterns.Windows.x86.RealmListBn;

                Console.ForegroundColor = ConsoleColor.White;
                Console.Write("Creating patched binaries for ");

                using (var patcher = new Patcher(args[0]))
                {
                    switch (patcher.Type)
                    {
                        case BinaryTypes.Pe32:
                            Console.WriteLine("Win32 client...");
                            modulePath        = commonAppData + "/Blizzard Entertainment/Battle.net/Cache/";
                            moduleFile        = "8f52906a2c85b416a595702251570f96d3522f39237603115f2f1ab24962043c.auth";
                            break;
                        //case BinaryTypes.Pe64:
                        //    Console.WriteLine("Win64 client...");
                        //    fileName   = patcher.Binary.Replace(".exe", "") + "_Patched.exe";

                        //    modulePath = commonAppData + "/Blizzard Entertainment/Battle.net/Cache/";
                        //    moduleFile = "0a3afee2cade3a0e8b458c4b4660104cac7fc50e2ca9bef0d708942e77f15c1d.auth";
                        //    break;
                        //case BinaryTypes.Mach32:
                        //    break;
                        //case BinaryTypes.Mach64:
                        //    Console.WriteLine("Mc64 client...");
                        //    patchBNet        = Patches.Mac.x64.BNet;
                        //    patternBNet      = Patterns.Mac.x64.BNet;
                        //    patchSend        = Patches.Mac.x64.Send;
                        //    patternSend      = Patterns.Mac.x64.Send;
                        //    patchSignature   = Patches.Mac.x64.Signature;
                        //    patternSignature = Patterns.Mac.x64.Signature;
                        //    fileName         = patcher.Binary + " Patched";

                        //    modulePath       = "/Users/Shared/Blizzard/Battle.net/Cache/";
                        //    moduleFile       = "97eeb2e28e9e56ed6a22d09f44e2ff43c93315e006bbad43bafc0defaa6f50ae.auth";
                        //    modulePatch      = Patches.Mac.x64.Password;
                        //    modulePattern    = Patterns.Mac.x64.Password;
                        //    break;
                        default:
                            throw new NotSupportedException("Type: " + patcher.Type + " not supported!");
                    }

                    if (!File.Exists(battleNetFileName + "_backup"))
                    {
                        File.Copy(battleNetFileName, battleNetFileName + "_backup");
                        File.SetAttributes(battleNetFileName + "_backup", File.GetAttributes(battleNetFileName + "_backup") | FileAttributes.ReadOnly);
                    }

                    using (var bnpatcher = new Patcher(battleNetFileName))
                    {
                        bnpatcher.Patch(patchBNet, null, offsetBNet);
                        bnpatcher.Patch(patchSignature, null, offsetSignature);
                        bnpatcher.Patch(realmListBnPatch, realmListBnPattern);
                        bnpatcher.Finish();
                    }

                    patcher.Patch(patchSend, null, offsetSend);
                    patcher.Patch(patchRecv, null, offsetRecv);
                    patcher.Patch(realmListPatch, null, realmListoffset);

                    patcher.Binary = fileName;

                    patcher.Finish();

                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("Patching done.");

                    CreateModule(moduleFile, modulePath, modulePatch, modulePattern);

                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("Successfully created your patched binaries.");
                }
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine("Wrong number of arguments: Missing client file.");
            }

            Console.ForegroundColor = ConsoleColor.Gray;
            Thread.Sleep(5000);
            Environment.Exit(0);
        }

        static void CreateModule(string moduleName, string path, byte[] patches, byte[] patterns)
        {
            var modulePath = path + moduleName[0] + moduleName[1] + "/" + moduleName[2] + moduleName[3];
            var module = modulePath + "/" + moduleName;

            if (!File.Exists(module))
            {
                Console.ForegroundColor = ConsoleColor.White;
                Console.WriteLine("Base module doesn't exist, downloading it...");

                if (!Directory.Exists(modulePath))
                    Directory.CreateDirectory(modulePath);

                var webClient = new WebClient();

                webClient.DownloadFileCompleted += (o, e) => PatchModule(module, path, patches, patterns);
                webClient.DownloadFileAsync(new Uri("http://xx.depot.battle.net:1119/" + moduleName), module);

                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Done.");
            }
            else
                PatchModule(module, path, patches, patterns);
        }

        static void PatchModule(string file, string path, byte[] patches, byte[] pattern)
        {
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine("Patching module...");

            using (var patcher2 = new Patcher(file))
            {
                patcher2.Patch(patches, pattern);

                var moduleName = Helper.GetFileChecksum(patcher2.binary) + ".auth";
                var modulePath = path + moduleName[0] + moduleName[1] + "/" + moduleName[2] + moduleName[3];

                if (!Directory.Exists(modulePath))
                    Directory.CreateDirectory(modulePath);

                patcher2.Binary = modulePath + "/" + moduleName;

                patcher2.Finish();
            }

            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("Patching module finished.");

            Console.ForegroundColor = ConsoleColor.Gray;
        }
    }
}
