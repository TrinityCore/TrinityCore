UPDATE `character` SET `name` = CONCAT(UCASE(SUBSTRING(`name`,1,1)),LCASE(SUBSTRING(`name`,2)));
