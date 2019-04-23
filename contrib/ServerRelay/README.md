# ServerRelay

Server Relay between world of warcraft world channel(AshamaneCore) and Discord.

### CREDITS
* Made by : __DEVIL1234__ 
* E-mail : __ingerasu1234@yahoo.com__.
* Credits for helping me : __Traesh__ from AshamaneProject
* Credits to guys with exceptional packages that simplified the process of making this project to happen

### Installation

To install this ServerRelay on your server(is more securely to run in same host with worldserver or internal on lan) you need to install Node.JS package and have setup a discord server and bot for it. Is already many tutorials how to setup this already on internet (google it bro). Tip : set the discordapp on developer mode, for id's right-click on channel's and select copy id.

SPECIAL REQUIREMENT : compile the worldserver with -DCPR=1 argument on cmake. ( will take a longer time to configure)

Recommended version of Node.JS : __v8.11.3__. Upper version is your risk to use.
1. Commands:
    ```javascript
    //That will install all packages needed from package.json and will be ready to use
    npm install
    ```
2. Configure the config.json file with your channels id and token from bot. The rest is preferable to not edit exception is the prefix for send command. Like this :
    ```javascript
    {
      "token": "BOT-TOKEN",
      "channel_id": "RELAY-CHAT-ID",
      "staff_channel_ID" : "STAFF-CHANNEL-ID",
      "post_url_server_message_world": "http://127.0.0.1:8082/sendChannelMessage/",
      "post_url_server_message_alliance" : "http://127.0.0.1:8082/sendChannelMessage/0",
      "post_url_server_message_horde" : "http://127.0.0.1:8082/sendChannelMessage/1",
      "post_url_server_command": "http://127.0.0.1:8082/command",
      "post_port": "8082",
      "post_token": "TOKEN FROM WORLDSERVER.CONF ON WorldREST.AuthToken, THIS ONE NEED TO MATCH HERE",
      "channel_horde" : "world_h",  // I RECOMMEND TO NOT CHANGE IT
      "channel_alliance": "world_a", // I RECOMMEND TO NOT CHANGE IT
      "allow_interactions" : "0", // IF YOU SET TO 1, YOU NEED TO ENABLE IN WORLDSERVER.CONF THIS ONE : AllowTwoSide.Interaction.Channel.
      "channel_world" : "world", // I RECOMMEND TO NOT CHANGE IT
      "command_prefix" : "." // IS USED ON staff channel for purge command(delete the message on channels) and send command for ingame commands(is same one from console)
    }
    ```
3. Configure the roles:
    ```javascript
    Open the server.js file with txt editor and read the comments line numbers : 13 -> 16
    ```
4. Running the server : 
    * Windows :
	<br /> WARNING: WILL RUN WITHOUT CMD PROMPT TO BE SHOWN
		```javascript
		Run the file windows.vbs
		```
	* Linux :
		```javascript
		chmod +x run.sh
		./linux.sh &
		
		// OPTIONALY CAND SET A CRONTAB WITH run.sh. THE SERVER IF IS WILL CRASH, THE NODEMON WILL TAKE OF SERVER.JS. IF YOU WANT TO SETUP CRONTAB ON THE END NOT SPECIFY `</dev/null>` BECAUSE IS ALREADY SPECIFIED ON linux.sh
		```

### Commands accessible on this discord bot
* Send
	```javascript
	(prefix)send argument(commands accessible on worldserver console)
	```
	* EXAMPLE :
		```javascript
		.send help // will return all commands available
		```

* Purge
	```javascript
	(prefix)purge <1-100> (will delete the message on channel(can be used on any channel)
	```
	* EXAMPLE
		* EXAMPLE :
		```javascript
		.purge 10 // delete 10 messages from channel
		```

### Support
If you need support for this relay contact me on discord server Ashamane under the username : __devil1234__. 
If you want to support with donations contact me same like up but on direct message/private message.