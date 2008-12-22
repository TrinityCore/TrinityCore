<?php

// Configuration.
// Realm database.
$r_db = "realmd";
// IP (and port).
$ip = "127.0.0.1:3306";
// Username.
$user = "trinity";
// Password.
$pass = "trinity";
// Site title.
$title = "Registration Form";
$title2 = "Some Server";
// End config.

$page = '<?xml version="1.0" encoding="utf-8" ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
<head>
<title>' . $title . '</title>
</head>
<body style="background-color:black;color:yellow;font-family:verdana;">
<form method="post" action="' . $_SERVER["SCRIPT_NAME"] . '">
<p style="text-align:center;">
<strong>' . $title2 . ' - ' . $title . '</strong>
<br /><br /><br />
Username:
<br /><input name="username" type="text" maxlength="14" /><br />
Password:
<br /><input name="password" type="password" maxlength="12" /><br />
Email:
<br /><input name="email" type="text" maxlength="50" />
<br /><input name="tbc" type="checkbox" checked="checked" /> TBC<br /><br /><br />
<button type="submit">Submit</button>
</p>
</form>
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
        if ((empty($_POST["username"]))||(empty($_POST["password"]))||(empty($_POST["email"]))||(empty($_POST["tbc"])) ) {
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
                if (strlen($password) < 8) {
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
                if ($_POST['tbc'] != "on") {
                        $tbc = "0";
                } else {
                        $tbc = "1";
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
                $register_sql = "insert into " . mysql_real_escape_string($r_db) . ".account (username, sha_pass_hash, email, expansion) values (upper('" . $username . "'),'" . $sha_pass_hash . "','" . $email . "','" . $tbc . "')";
                $qry = @mysql_query($register_sql, $con);
				if (!$qry) {
					error_s("Error creating account: " . mysql_error());
				};
                echo("Account successfully created.");
				exit();
        };
} else {
        echo($page);
};

?>
