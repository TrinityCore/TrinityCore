<?php
session_start();
include("db.conf.php");

$page = '<?xml version="1.0" encoding="utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<style type="text/css">

#tooltip{
position: absolute;
left: -300px;
width: 150px;
border: 1px solid black;
padding: 2px;
background-color: black;
visibility: hidden;
z-index: 100;
filter: progid:DXImageTransform.Microsoft.Shadow(color=gray,direction=135);
}

#dhtmlpointer{
position:absolute;
left: -300px;
z-index: 101;
visibility: hidden;
}
</style>
<title>' . $title . '</title>
</head>
<body style="background-color:black;color:yellow;font-family:verdana;">
<script type="text/javascript">
var offsetfromcursorX=12 //Customize x offset of tooltip
var offsetfromcursorY=10 //Customize y offset of tooltip

var offsetdivfrompointerX=10 //Customize x offset of tooltip DIV relative to pointer image
var offsetdivfrompointerY=14 //Customize y offset of tooltip DIV relative to pointer image. Tip: Set it to (height_of_pointer_image-1).

document.write(\'<div id="tooltip"></div>\') //write out tooltip DIV
document.write(\'<img id="dhtmlpointer" src="inc/arrow2.gif">\') //write out pointer image

var ie=document.all
var ns6=document.getElementById && !document.all
var enabletip=false
if (ie||ns6)
var tipobj=document.all? document.all["tooltip"] : document.getElementById? document.getElementById("tooltip") : ""

var pointerobj=document.all? document.all["dhtmlpointer"] : document.getElementById? document.getElementById("dhtmlpointer") : ""

function ietruebody(){
return (document.compatMode && document.compatMode!="BackCompat")? document.documentElement : document.body
}

function ttip(thetext, thewidth, thecolor){
if (ns6||ie){
if (typeof thewidth!="undefined") tipobj.style.width=thewidth+"px"
if (typeof thecolor!="undefined" && thecolor!="") tipobj.style.backgroundColor=thecolor
tipobj.innerHTML=thetext
enabletip=true
return false
}
}

function positiontip(e){
if (enabletip){
var nondefaultpos=false
var curX=(ns6)?e.pageX : event.clientX+ietruebody().scrollLeft;
var curY=(ns6)?e.pageY : event.clientY+ietruebody().scrollTop;
var winwidth=ie&&!window.opera? ietruebody().clientWidth : window.innerWidth-20
var winheight=ie&&!window.opera? ietruebody().clientHeight : window.innerHeight-20

var rightedge=ie&&!window.opera? winwidth-event.clientX-offsetfromcursorX : winwidth-e.clientX-offsetfromcursorX
var bottomedge=ie&&!window.opera? winheight-event.clientY-offsetfromcursorY : winheight-e.clientY-offsetfromcursorY

var leftedge=(offsetfromcursorX<0)? offsetfromcursorX*(-1) : -1000

if (rightedge<tipobj.offsetWidth){
tipobj.style.left=curX-tipobj.offsetWidth+"px"
nondefaultpos=true
}
else if (curX<leftedge)
tipobj.style.left="5px"
else{
tipobj.style.left=curX+offsetfromcursorX-offsetdivfrompointerX+"px"
pointerobj.style.left=curX+offsetfromcursorX+"px"
}

if (bottomedge<tipobj.offsetHeight){
tipobj.style.top=curY-tipobj.offsetHeight-offsetfromcursorY+"px"
nondefaultpos=true
}
else{
tipobj.style.top=curY+offsetfromcursorY+offsetdivfrompointerY+"px"
pointerobj.style.top=curY+offsetfromcursorY+"px"
}
tipobj.style.visibility="visible"
if (!nondefaultpos)
pointerobj.style.visibility="visible"
else
pointerobj.style.visibility="hidden"
}
}

function hidettip(){
if (ns6||ie){
enabletip=false
tipobj.style.visibility="hidden"
pointerobj.style.visibility="hidden"
tipobj.style.left="-1000px"
tipobj.style.backgroundColor=\'\'
tipobj.style.width=\'\'
}
}
document.onmousemove=positiontip
</script>
<form method="post" action="' . $_SERVER["SCRIPT_NAME"] . '">
<p style="text-align:center;">
<strong>' . $title2 . ' - ' . $title . '</strong>
<br /><br /><br />
Username:
<br /><input name="username" type="text" maxlength="14" /><img src="inc/help.gif" HEIGHT="20" WIDTH="20" alt="help" onMouseover="ttip(\'username must be 5 - 14 chars long\', 300)"; onMouseout="hidettip()"><br />
Password:
<br /><input name="password" type="password" maxlength="12" onkeyup="runPassword(this.value, \'mypassword\');" /><img src="inc/help.gif" HEIGHT="20" WIDTH="20" alt="help" onMouseover="ttip(\'Password must be 6 - 12 chars long\', 300)"; onMouseout="hidettip()">
<div style="width: 100px;text-align:center;"> 
				<div id="mypassword_text" style="font-size: 10px;"></div>
				<div id="mypassword_bar" style="font-size: 1px; height: 2px; width: 0px; border: 1px solid white;"></div> 
			</div></p>
<br />
<p style="text-align:center;">Email:
<br /><input name="email" type="text" maxlength="50" /><img src="inc/help.gif" HEIGHT="20" WIDTH="20" alt="help" onMouseover="ttip(\'Email must be 15 - 50 chars long\', 300)"; onMouseout="hidettip()"><br />
<INPUT TYPE=RADIO NAME="expansion" VALUE="0"         >Original - 
<INPUT TYPE=RADIO NAME="expansion" VALUE="1" CHECKED >TBC - 
<INPUT TYPE=RADIO NAME="expansion" VALUE="2"         >WOTLK<br />
<img src="inc/OOP5.php" style="border: 1px dashed silver;"><br />
<span style="font-size:9px;"><a href="">New question</a></span><br />
<input type="text" style="width:160px;" name="AnimCaptcha"><img src="inc/help.gif" HEIGHT="20" WIDTH="20" alt="help" onMouseover="ttip(\'Are you a bot? are you? thats it...im getting my junior torturer kit, dont go anywhere i\'ll be right back.\', 300)"; onMouseout="hidettip()"><br />
<br />
<img src="inc/help.gif" HEIGHT="20" WIDTH="20" alt="help" onMouseover="ttip(\'Yes everything must be filled. quit whining.\', 300)"; onMouseout="hidettip()"><button type="submit">Submit</button>
</p>
</form>
<script type="text/javascript" src="inc/pwd_strength.js"></script>
</body>
</html>';

function error_s ($text) {
	echo("<p style=\"background-color:black;color:yellow;font-family:verdana;\">" . $text);
	echo("<br /><br /><a style=\"color:orange;\" href=\"" . $_SERVER["SCRIPT_NAME"] . "\">Go back...</a></p>");
};

$user_chars = "#[^a-zA-Z0-9_\-]#";
$email_chars = "/^[^0-9][A-z0-9_]+([.][A-z0-9_]+)*[@][A-z0-9_]+([.][A-z0-9_]+)*[.][A-z]{2,4}$/";

$con = @mysql_connect($ip, $user, $pass);
if (!$con) {
	error_s("Unable to connect to database: " . mysql_error());
};

if (!empty($_POST)) {
        if ((empty($_POST["username"]))||(empty($_POST["password"]))||(empty($_POST["email"]))||(empty($_POST["expansion"])) ) {
                error_s("You did not enter all the required information.");
				exit();
        } else {
                $username = strtoupper($_POST["username"]);
                $password = strtoupper($_POST["password"]);
                $email = strtoupper($_POST["email"]);
                if (strlen($username) < 5) {
                        error_s("Username too short.");
                        exit();
                };
                if (strlen($username) > 14) {
                        error_s("Username too long.");
                        exit();
                };
                if (strlen($password) < 6) {
                        error_s("Password too short.");
                        exit();
                };
                if (strlen($password) > 12) {
                        error_s("Password too long.");
                        exit();
                };
                if (strlen($email) < 15) {
                        error_s("Email was too short.");
                        exit();
                };
				if (strlen($email) > 50) {
                        error_s("Email was too long.");
                        exit();
                };
                if (preg_match($user_chars,$username)) {
                        error_s("Username contained illegal characters.");
                        exit();
                };
                if (preg_match($user_chars,$password)) {
                        error_s("Password contained illegal characters.");
                        exit();
                };
                if (!preg_match($email_chars,$email)) {
                        error_s("Email was in an incorrect format.");
                        exit();
                };
                $username = mysql_real_escape_string($username);
                $password = mysql_real_escape_string($password);
                $email = mysql_real_escape_string($email);
                $qry = @mysql_query("select username from " . mysql_real_escape_string($r_db) . ".account where username = '" . $username . "'", $con);
				if (!$qry) {
					error_s("Error querying database: " . mysql_error());
				};
                if ($existing_username = mysql_fetch_assoc($qry)) {
                        foreach ($existing_username as $key => $value) {
                                $existing_username = $value;
                        };
                };
                $existing_username = strtoupper($existing_username);
                if ($existing_username == strtoupper($_POST['username'])) {
                        error_s("That username is already taken.");
                        exit();
                };
				unset($qry);
                $qry = @mysql_query("select email from " . mysql_real_escape_string($r_db) . ".account where email = '" . $email . "'", $con);
				if (!$qry) {
					error_s("Error querying database: " . mysql_error());
				};
                if ($existing_email = mysql_fetch_assoc($qry)) {
                        foreach ($existing_email as $key => $value) {
                                $existing_email = $value;
                        };
                };
                if ($existing_email == $_POST['email']) {
                        error_s("That email is already in use.");
                        exit();
                };
				unset($qry);
                $sha_pass_hash = sha1(strtoupper($username) . ":" . strtoupper($password));
                $register_sql = "insert into " . mysql_real_escape_string($r_db) . ".account (username, sha_pass_hash, email, expansion) values (upper('" . $username . "'),'" . $sha_pass_hash . "','" . $email . "','" . $expansion . "')";
		if (isset($_POST['AnimCaptcha']))
            {
              if (is_numeric($_POST['AnimCaptcha']))
                {
                  if ( $_POST['AnimCaptcha'] == $_SESSION['answer'])
                    {
					  $qry = @mysql_query($register_sql, $con);
                    }
                  else
                    {
                      error_s("Captcha not filled properly</b></p><p><a href=''>Try again</a></p>");
                        exit();
                    }
                }
              else
                {
				  error_s("<p><b>Enter Numbers or (+/-) only.  No alphabetical characters accepted.</b></p><p><a href=''>Try again</a></p>");
                        exit();
                }
            }
                if (!$qry) {
					error_s("Error creating account: " . mysql_error());
				};
                echo("Account successfully created.");
				exit();
        };
} else {
        echo($page);
};

echo '<center><a href="http://www.trinitycore.org">Trinity Powered</a></center>';

?>