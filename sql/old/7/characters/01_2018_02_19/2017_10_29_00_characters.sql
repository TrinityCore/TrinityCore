UPDATE `characters` SET `taxi_path`=CONCAT('0 ', `taxi_path`) WHERE LENGTH(`taxi_path`) > 0;
