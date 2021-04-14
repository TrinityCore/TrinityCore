UPDATE `characters` SET `knownTitles`=SUBSTRING_INDEX(CONCAT(`knownTitles`, ' 0 0 0 0 0 0 0 0 0 0 0 0'), ' ', 12);
