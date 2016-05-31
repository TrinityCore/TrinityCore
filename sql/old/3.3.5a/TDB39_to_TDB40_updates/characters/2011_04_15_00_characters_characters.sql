-- append extra zeros, only if the string is properly formatted (has 38 tokens)
UPDATE `characters` SET `equipmentCache`=CONCAT(`equipmentCache`,"0 0 0 0 0 0 0 0 ") WHERE (CHAR_LENGTH(`equipmentCache`) - CHAR_LENGTH(REPLACE(`equipmentCache`, ' ', ''))) = 38;
