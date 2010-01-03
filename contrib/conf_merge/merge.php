<?php
/*
 * Project Name: Config File Merge For Mangos/Trinity Server
 * Date: 01.01.2010 inital version (0.0.1a)
 * Author: Paradox
 * Copyright: Paradox
 * Email: iamparadox@netscape.net (paypal email)
 * License: GNU General Public License v2(GPL)
 */
if (!empty($_FILES['File1']) && !empty($_FILES['File2']))
{
    session_id();
    session_start();
    $basedir = "merge";
    $eol = "\r\n";
    if ($_POST['eol'])
        $eol = "\n";
    else
        $eol = "\r\n";
    if (!file_exists($basedir))
        mkdir($basedir);
    if (!file_exists($basedir."/".session_id()))
        mkdir($basedir."/".session_id());
    $upload1 = $basedir."/".session_id()."/".basename($_FILES['File1']['name']);
    $upload2 = $basedir."/".session_id()."/".basename($_FILES['File2']['name']);
    $newconfig = $basedir."/".session_id()."/trinitycore.conf.merged";
    $out_file = fopen($newconfig, w);
    $success = false;
    if (move_uploaded_file($_FILES['File1']['tmp_name'], $upload1))
    {
        $success = true;
    }
    else
    {
        $success = false;
    }
    if (move_uploaded_file($_FILES['File2']['tmp_name'], $upload2))
    {
        $success = true;
    }
    else
    {
        $success = false;
    }

    if ($success)
    {
        $custom_found = false;
        $in_file1 = fopen($upload1,r);
        $in_file2 = fopen($upload2,r);
        $array1 = array();
        $array2 = array();
        $line = trim(fgets($in_file1));
        while (!feof($in_file1))
        {
            if ((substr($line,0,1) != '#' && substr($line,0,1) != ''))
            {
                    list($key, $val) = explode("=",$line);
                    $key = trim($key);
                    $val = trim($val);
                    $array1[$key] = $val;
            }
            $line = trim(fgets($in_file1));
        }
        $line = trim(fgets($in_file2));
        while (!feof($in_file2) && !$custom_found)
        {
            if (substr($line,0,1) != '#' && substr($line,0,1) != '')
            {
                    list($key, $val) = explode("=",$line);
                    $key = trim($key);
                    $val = trim($val);
                    $array2[$key] = $val;
            }
            if (strtolower($line) == "# custom")
               $custom_found = true;
            else
                $line = trim(fgets($in_file2));
        }
        fclose($in_file1);
        foreach($array2 as $k => $v)
        {
            if (array_key_exists($k, $array1))
            {
                $array1[$k] = $v;
                unset($array2[$k]);
            }
        }
        $in_file1 = fopen($upload1,r);
        $line = trim(fgets($in_file1));
        while (!feof($in_file1))
        {
            if (substr($line,0,1) != '#' && substr($line,0,1) != '')
            {
                $array = array();
                while (substr($line,0,1) != '#' && substr($line,0,1) != '')
                {
                    list($key, $val) = explode("=",$line);
                    $key = trim($key);
                    $val = trim($val);
                    $array[$key] = $val;
                    $line = trim(fgets($in_file1));
                }
                foreach($array as $k => $v)
                {
                    if (array_key_exists($k, $array1))
                        fwrite($out_file, $k."=".$array1[$k].$eol);
                    else
                        continue;
                }
                unset($array);
                if (!feof($in_file1))
                    fwrite($out_file, $line.$eol);
            }
            else
                fwrite($out_file, $line.$eol);
            $line = trim(fgets($in_file1));
        }
        if ($custom_found)
        {
            fwrite($out_file, $eol);
            fwrite($out_file, "###############################################################################".$eol);
            fwrite($out_file, "# Custom".$eol);
            $line = trim(fgets($in_file2));
            while (!feof($in_file2))
            {
                fwrite($out_file, $line.$eol);
                $line = trim(fgets($in_file2));
            }
        }
        $first = true;
        foreach($array2 as $k => $v)
        {
            if ($first)
            {
                fwrite($out_file, $eol);
                fwrite($out_file, "###############################################################################".$eol);
                fwrite($out_file, "#      The Following values were removed from the config.".$eol);
                $first = false;
            }
            fwrite($out_file, "#          ".$k."=".$v.$eol);
        }
        unset($array1);
        unset($array2);
        fclose($in_file1);
        fclose($in_file2);
        fclose($out_file);
        unlink($upload1);
        unlink($upload2);

        echo "Process done";
        echo "<br /><a href=".$newconfig.">Click here to retrieve your merged conf</a>";
    }
}
else
{
    echo "An error has occurred";
}
?>
