UPDATE `characters` SET `zone`=0 WHERE (`at_login` & 0x20) != 0;
