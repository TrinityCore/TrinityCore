-------------------------------------------------------

# XP Weekend module


## Description

This module is a xp module that will allow the server owner/host to select how much XP players can recieve on the weekend via a config file.


## How to use ingame

Apply the module and Just log in on the weekend there you will see an announcement upon login to see if the module has been activated.

## Requirements

My new module requires:

- AzerothCore v1.0.1+


## Installation

```
1) Simply place the module under the `modules` directory of your AzerothCore source. 
2) Import the SQL manually to the right Database (auth, world or characters) or with the `db_assembler.sh` (if `include.sh` provided).
3) Re-run cmake and launch a clean build of AzerothCore.
```

## Edit module configuration (optional)

If you need to change the module configuration, go to your server configuration folder (where your `worldserver` or `worldserver.exe` is), copy `mod-double-xp-weekend.conf.dist` to `mod-double-xp-weekend.conf` and edit that new file.


## Credits

* [Me](https://github.com/Talamortis) (author of the module)

AzerothCore: [repository](https://github.com/azerothcore) - [website](http://azerothcore.org/) - [discord chat community](https://discord.gg/PaqQRkd)
