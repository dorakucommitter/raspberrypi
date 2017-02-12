CREATE TABLE IF NOT EXISTS `measure_data` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `epoch_time` INT NULL,
  `temperature` INT NULL,
  `humid` INT NULL,
  `pressure` INT NULL,
  `create_at` TIMESTAMP NULL,
  PRIMARY KEY (`id`));

