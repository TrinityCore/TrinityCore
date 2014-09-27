<!--
  @title   Configuration file merger/differ.
  @about   This script allows you to diff two config files and select which value to pick between the two.
           It will then give you an updated configuration file with the settings you chose.
           How-to: a) Paste both versions of your config file, submit the form.
                   b) Select values you want to keep in the next form, then submit said form.
                   c) Copy the output'd config file and profit!
           Note: if either one of your config file has custom values, make sure that it is set to be the NEW
                 config file on the first step (right hand textarea). This will be adressed at a later date.
  @author  Warpten
  @date    05/17/2014
  @license GNU GPL v2(GPL)
  @version 0.0.1
-->
<!DOCTYPE html>
<html>
<head>
    <title>&lt;world/auth&gt;server.conf diff</title>
    <style type="text/css">
    form * { font-family: Verdana; font-size: 11px; }
    form#step1 { position: relative; width: 800px; }
    form#step2 { width: 500px; }
    form > div { position: absolute; width: 50%; height: 500px; }
    form > div:nth-child(1) { right: 0px; }
    textarea { width: 90%; height: 500px; }
    h3 { display: block; margin: 3px; padding: auto; text-align: center; }
    input.valueName { border: 0px; background-color: white; }
    form > p { margin: 0; padding: 3px; border-bottom: 1px solid black; }
    textarea#result { width: 1000px; }
    </style>
</head>

<body>
<?php

function printIndent($string, $indent = 1)
{
    echo str_pad("\r\n" . $string, $indent, "    ");
}

if (!isset($_POST['step']))
{
?>
    <form action="" method="POST" id="step1">
        <div>
            <h3>Paste the new configuration file</h3>
            <textarea name="leftFile"></textarea>
        </div><div>
            <h3>Paste the old configuration file</h3>
            <textarea name="rightFile"></textarea>
            <input type="submit" value="Compare files" />
        </div>
        <input type="hidden" name="step" value="0" />
    </form>
<?php
}
else if ($_POST['step'] == 0)
{
    if (@empty($_POST['leftFile']) || @empty($_POST['rightFile']))
        printf("You did not provide either the old or the new configuration file.<br />");

    define('EOL', "\n\n");
    $settingsData = array();

    // Process them
    $newFile = explode(EOL, $_POST['leftFile']);
    $oldFile = explode(EOL, $_POST['rightFile']);
    
    for ($i = 0, $o = count($oldFile); $i < $o; ++$i)
    {
        $oldFile[$i] = explode(PHP_EOL, $oldFile[$i]);
        for ($j = 0, $p = count($oldFile[$i]); $j < $p; ++$j)
        {
            $currentLine = $oldFile[$i][$j];
            if (preg_match("#^([A-Z.]+) = (?:\"?)(.*)(?:\"?)$#iU", $currentLine, $data) !== false)
                if (strlen($data[1]) != 0)
                    $settingsData[$data[1]]["oldValue"] = str_replace('"', '', trim($data[2]));
        }
    }
    
    for ($i = 0, $o = count($newFile); $i < $o; ++$i)
    {
        $newFile[$i] = explode(PHP_EOL, $newFile[$i]);
        for ($j = 0, $p = count($newFile[$i]); $j < $p; ++$j)
        {
            $currentLine = $newFile[$i][$j];
            if (preg_match("#^([A-Z.]+) = (?:\"?)(.*)(?:\"?)$#iU", $currentLine, $data) !== false)
                if (strlen($data[1]) != 0)
                    $settingsData[$data[1]]["newValue"] = str_replace('"', '', trim($data[2]));
        }
    }
    
    printIndent("<p>Please select values you want to keep. Note the script will default to new values, unless said <i>new</i> value does not exist.<br />You also can take advantage of this form and edit fields.</p>", 1);
    printIndent('<form action="" method="POST" id="step2">', 1);

    foreach ($settingsData as $itemName => &$values)
    {
        $displayOld = isset($values['oldValue']) ? $values['oldValue'] : "Value missing";
        $displayNew = isset($values['newValue']) ? $values['newValue'] : "Value missing";
        
        if ($displayOld == $displayNew)
            continue;
        
        $line  = '<p><input type="text" class="valueName" name="nameCross[]" value="' . $itemName . '" />';
        $line .= '<input type="radio" name="optionSelector[' . $itemName . ']" value="oldValue" ' . ($displayOld != "Value missing" ? "checked" : "") . '/>';
        $line .= '<input type="text" name="oldValue[]" value="' . $displayOld . '" /> ';
        $line .= '<input type="radio" name="optionSelector[' . $itemName . ']" value="newValue" ' . ($displayNew != "Value missing" ? "checked" : "") . '/>';
        $line .= '<input type="text" name="newValue[]" value="' . $displayNew . '" /></p>';
        printIndent($line, 2);
    }
    printIndent('<input type="hidden" name="step" value="1" />', 2);
    printIndent('<input type="submit" value="Gief resulting configuration file" />', 2);
    printIndent('<input type="hidden" name="file" value="' . htmlspecialchars($_POST['rightFile']) . '" />', 2);
    printIndent('</form>', 1);
}
else if ($_POST['step'] == 1)
{
    $errors = array();
    
    $confFile = $_POST['file'];

    foreach ($_POST['optionSelector'] as $valueName => &$keyName)
    {
        $definiteValueIndex = -1;
        foreach ($_POST['nameCross'] as $index => &$key)
        {
            if ($key == $valueName)
            {
                $definiteValueIndex = $index;
                break;
            }
        }
        
        if ($definiteValueIndex == -1)
        {
            // TODO: Handle custom values that get lost
            continue;
        }

        $newStr = $_POST[$keyName][$definiteValueIndex];
        $oldStr = $_POST[$keyName == "oldValue" ? "newValue" : "oldValue"][$definiteValueIndex];
        if (!ctype_digit($newStr))
            $newStr = '"' . $newStr . '"';
        if (!ctype_digit($oldStr))
            $oldStr = '"' . $oldStr . '"';
        
        $newValueString = $valueName . " = " . $newStr;
        $oldValueString = $valueName . " = " . $oldStr;
        $confFile = str_replace($oldValueString, $newValueString, $confFile);
    }
    echo "<p>Here is your new configuration file:</p>";
    echo '<form><textarea id="result">';
    printf('%s', $confFile);
    echo '</textarea></form>';
    
    if (!empty($errors))
    {
        echo "<p>The following errors happened during processing:</p><ul><li>";
        echo implode("</li><li>", $errors);
        echo "</li>";
    }
}
?>

<script type="text/javascript">

</script>
</body>
</html>
