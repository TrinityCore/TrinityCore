# Clean old account_transfer character data ( keeping other information about the transfer )

UPDATE account_transfer SET cDump = "CLEANED", cItemRow = "CLEANED" WHERE date_created < '2015-08-15 00:00:00' AND cStatus <> 0;
