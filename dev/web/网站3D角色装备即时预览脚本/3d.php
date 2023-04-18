<?php 
$config['ip'] = "localhost";
$config['user'] = "xxx";
$config['pass'] = "xxx";
$config['char_db'] = "character";
$config['world_db'] = "world";



if(is_numeric($_REQUEST["guid"])){
    $player_guid = $_REQUEST["guid"];
}else {
    $player_guid = 0;
}


mysql_connect($config['ip'], $config['user'], $config['pass']);
mysql_select_db($config['char_db']);

$sql = mysql_query("SELECT data, race, gender FROM characters WHERE guid = '".mysql_real_escape_string($player_guid)."'");
$result = mysql_fetch_array($sql);

$data = explode(' ',$result['data']);


$item_head = $data[258];
$item_neck = $data[260];
$item_shoulder = $data[262];
$item_shirt = $data[264];
$item_chest = $data[266];
$item_belt = $data[268];
$item_legs = $data[270];
$item_feet = $data[272];
$item_wrist = $data[274];
$item_gloves = $data[276];
$item_finger1 = $data[278];
$item_finger2 = $data[280];
$item_trinket1 = $data[282];
$item_trinket2 = $data[284];
$item_back = $data[286];
$item_main_hand = $data[288];
$item_off_hand = $data[290];
$item_ranged_slot = $data[292];




function wowhead_did($item) {
    global $config;
    mysql_select_db($config['world_db']);
    $sql = mysql_query("SELECT displayid FROM item_template WHERE entry = '".$item."'");
    $displayid = mysql_result($sql, 0);  
    
    echo $displayid;

}

function char_racegender($race, $gender) {

    $char_race = array(
        1 => 'human',
        2 => 'orc',
        3 => 'dwarf',
        4 => 'nightelf',
        5 => 'scourge',
        6 => 'tauren',
        7 => 'gnome',
        8 => 'troll',
        10 => 'bloodelf',
        11 => 'draenei');
        
    $char_gender = array(
        0 => 'male',
        1 => 'female');

    echo $char_race[$race].$char_gender[$gender];

}  
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
    <head>
        <meta http-equiv="Expires" content="Fri, Jan 01 1900 00:00:00 GMT">
        <meta http-equiv="Pragma" content="no-cache">
        <meta http-equiv="Cache-Control" content="no-cache">
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <meta http-equiv="Lang" content="en">
        <meta name="author" content="">
        <meta http-equiv="Reply-to" content="@.com">
        <meta name="generator" content="PhpED 5.6">
        <meta name="description" content="">
        <meta name="keywords" content="">
        <meta name="creation-date" content="11/11/2008">
        <meta name="revisit-after" content="15 days">
        <title>3D Charakter Ansicht</title>

    </head>
    <body>
        <div id="model_scene" align="center">
            <object id="wowhead" type="application/x-shockwave-flash" data="http://static.wowhead.com/modelviewer/ModelView.swf" height="800px" width="600px">
                <param name="quality" value="high">
                <param name="allowscriptaccess" value="always">
                <param name="menu" value="false">
                <param value="transparent" name="wmode">
                <param name="flashvars" value="model=<?php char_racegender($result['race'], $result['gender']); ?>&amp;modelType=16&amp;ha=0&amp;hc=0&amp;fa=0&amp;sk=0&amp;fh=0&amp;fc=0&amp;contentPath=http://static.wowhead.com/modelviewer/&amp;blur=1&amp;equipList=1,<?php wowhead_did($item_head); ?>,3,<?php wowhead_did($item_shoulder); ?>,16,<?php wowhead_did($item_back); ?>,5,<?php wowhead_did($item_chest); ?>,9,<?php wowhead_did($item_wrist); ?>,10,<?php wowhead_did($item_gloves); ?>,6,<?php wowhead_did($item_belt); ?>,7,<?php wowhead_did($item_legs); ?>,8,<?php wowhead_did($item_feet); ?>,14,<?php wowhead_did($item_off_hand); ?>,21,<?php wowhead_did($item_main_hand); ?>">
                <param name="movie" value="http://static.wowhead.com/modelviewer/ModelView.swf">
            </object>
        </div>  
  </body>
</html>