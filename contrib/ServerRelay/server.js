
/* requirements */
var Discord = require("discord.js");
var config = require("./config.json")
var client = new Discord.Client();
const request = require('request');
const http = require('http');
var rp = require('request-promise');
const parseJson = require('parse-json');
var emoji = require('node-emoji');
var empty = require('is-empty');

// CONFIGURE THE ROLES NEEDED FOR GM Logo
// If you want more roles added just do like this (append to original one on line 95 and 195(optionaly, for send command) with 
// || message.member.roles.find("name", role_3+) and add const role_number here.
// If you want just to change role name, modify the attribute below . Example : Admin -> Your role name
role_1 = "Owner";
role_2 = "GameMasters";

/* Ready the client */
client.on('ready', () => {
    console.log('I am ready!');
    
    client.user.setPresence({game: {name: "WORD PORN", type: 0}});
    client.user.setStatus('dnd');
    //console.log(`Logged in as ${client.user.tag}!`);

    var server = http.createServer(OnWorldMessage);
    OnDiscordMessage();
    Commands();
    server.listen(8083);
});

client.on("disconnected", function () { process.exit(1); });
/*
 * Handle message in the way "World => Discord"
 */
function OnWorldMessage(request, response) {
    if (request.method != "POST") {
        response.writeHead(404);
        response.end();
        return;
    }

    try {
        let body = [];
        request.on('data', (chunk) => {
            body.push(chunk);
        }).on('end', () => {
            body = Buffer.concat(body).toString();
            //console.log(body);

            /*Send the message to discord*/
			
			// Parse the json message to can return part from it
            var myJSON = JSON.parse(body);
            //console.log(string);
			
			// send to discord channel id and the json text
            switch(config.allow_interactions)
            {
                case "1":
                    client.channels.get(config.channel_id).send(myJSON.text);
                    break;
                case "0":
                    var string = "[" + myJSON.channel + "]" + " " + myJSON.text;
                    client.channels.get(config.channel_id).send(string);
                    break;
            }

            response.writeHead(200);
            response.end();
        });
    }
    catch (e) {
        console.log(e);
        response.writeHead(500);
        response.end();
    }
}

/*
 * Handle message in the way "Discord => World"
 */
 
function OnDiscordMessage() {

    client.on('message', async message => {
        if (message.author.bot) return;
        if (message.channel.type === "dm") return;
        
        // SEND TO WORLD CHANNEL
	    // showGMlogo bollean
        if(message.channel.id === config.channel_id){
            if(message.member.roles.find("name", role_1) || message.member.roles.find("name", role_2)) {var gmLOGO = '1'} else { gmLOGO = "0"};

            const messageArray = message.content;
            const author = message.member.user.username;
            
            const message_emoji_replace = emoji.replace(messageArray, (emoji) => `${emoji.key}`);
            
            // world channel
            let json_world = JSON.stringify({"senderName":author,"channelName":config.channel_world,"message": message_emoji_replace, "showGMLogo": gmLOGO});
            // world_a channel
            let json_world_a = JSON.stringify({"senderName":author,"channelName":config.channel_alliance,"message": message_emoji_replace, "showGMLogo": gmLOGO});
            // world_h channel
            let json_world_h = JSON.stringify({"senderName":author,"channelName":config.channel_horde,"message": message_emoji_replace, "showGMLogo": gmLOGO});
            
            // allow interactions between horde and alliance on world channel's
            
            switch (config.allow_interactions){
                case "1":
                    var url_0 = config.post_url_server_message_world + "0";
                    var url_1 = config.post_url_server_message_world + "1";
                    
                    console.log(url_0);
                
                    var auth = { 'Authorization': config.post_token};
                    request.post({url:url_0, form: json_world, headers: auth}, function(err, httpResponse,body)
                    {
                        if(err) {
                            return console.log(err); 
                        }
                        //console.log('post Suceess the response is:', body);
                    });
                    
                    var auth = { 'Authorization': config.post_token};
                    request.post({url:url_1, form: json_world, headers: auth}, function(err, httpResponse,body)
                    {
                        if(err) {
                            return console.log(err); 
                        }
                        //console.log('post Suceess the response is:', body);
                    });
                    break;
                case "0":
                    var auth = { 'Authorization': config.post_token};
                    
                    request.post({url:config.post_url_server_message_alliance, form: json_world_a, headers: auth}, function(err, httpResponse,body)
                    {
                        if(err) {
                            return console.log(err); 
                        }
                        console.log('post Suceess the response is:', body);
                    });
                    
                    request.post({url:config.post_url_server_message_horde, form: json_world_h, headers: auth}, function(err, httpResponse,body)
                    {
                        if(err) {
                            return console.log(err); 
                        }
                        //console.log('post Suceess the response is:', body);
                    });
                    break;
//              default:
                    
            };
        };
    });
};

/*
 * Handle the commands
 */
function Commands() {
    
    client.on('message', async message => {
        if (message.author.bot) return;
        if (message.channel.type === "dm") return;

        const args = message.content.slice(config.command_prefix.length).trim().split(/ +/g);
        const command = args.shift().toLowerCase();
        
        if(message.content.indexOf(config.command_prefix) !== 0) return;
        
        // COMMAND POST COMMANDS
        if(command === "purge") {
        
            // This command removes all messages from all users in the channel, up to 100.

            // get the delete count, as an actual number.
            const deleteCount = parseInt(args[0], 10);

            // Ooooh nice, combined conditions. <3
            if(!deleteCount || deleteCount < 2 || deleteCount > 1000)
                return message.reply("Please provide a number between 2 and 100 for the number of messages to delete");

            // So we get our messages, and delete them. Simple enough, right?
            const fetched = await message.channel.fetchMessages({limit: deleteCount});
            message.channel.bulkDelete(fetched)
                .catch(error => message.reply(`Couldn't delete messages because of: ${error}`));
        };
        
        if(message.channel.id === config.staff_channel_ID){
            if(message.member.roles.find("name", role_1) || message.member.roles.find("name", role_2)) 
            {
                if(command === "send") {
                    const sendCommand = args.join(" ");

                    message.delete().catch(O_o=>{});
                    
                    //let json = {"command":sendCommand}
                    
                    //console.log(args.length);
                    if (args != null && args.length > 0) 
                    {
                    
                        //let json_string = JSON.stringify(json)
                        var auth = { 'Authorization': config.post_token}
                        
                        var options = {method: 'POST', uri: config.post_url_server_command, body: {"command":sendCommand} ,headers: auth, json: true, resolveWithFullResponse: true, needReadable: true};
                        
                        rp(options).then(function (response) { 
                                //console.log(response);
                                var myJSONString = JSON.stringify(response.body);
                                //console.log(myJSONString);
                                var myEscapedJSONString = myJSONString.replace(/\\r/g, "").replace(/\\n/g, "").replace(/\s\s+/g, " ");
                                if (myEscapedJSONString === myJSONString)
                                {
                                    var b = JSON.parse(myEscapedJSONString);
                                    //console.log("this is b:", b);
                                    //console.log(b.message);
                                    message.channel.send("The command was sent to worldserver.");
                                } else {
                                    var a = JSON.parse(JSON.parse(myEscapedJSONString));
                                    //console.log("this is a :" ,a)
                                    //console.log(a.message);
                                    message.channel.send("Your command response is: " + a.message);
                                }
                                
                        }).catch(function (err) {
                            console.log(err)
                        })
                    }
                    else { 
                        message.channel.send("You can't send emty command");
                    };
                };
            } else { message.channel.send("Not enough permission to use this command. Contact Admin or Gamemaster to ban you :smile:"); };
        };
    });
}

client.login(config.token);
