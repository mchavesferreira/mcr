CREATE DATABASE IF NOT EXISTS voltametrico
  CHARACTER SET utf8mb4
  COLLATE utf8mb4_unicode_ci;

USE voltametrico;

CREATE TABLE IF NOT EXISTS cv_runs (
    id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
    run_id VARCHAR(48) NOT NULL,
    nome_amostra VARCHAR(120) NULL,
    observacoes VARCHAR(255) NULL,

    v_start_mv INT NOT NULL,
    v_vertex1_mv INT NOT NULL,
    v_vertex2_mv INT NOT NULL,
    v_end_mv INT NOT NULL,

    step_mv INT NOT NULL,
    scan_rate_mv_s DECIMAL(12,4) NOT NULL,
    cycles INT NOT NULL,
    gain_initial TINYINT NOT NULL,

    quiet_time_ms INT NOT NULL,
    sample_interval_ms INT NOT NULL,
    settle_ms INT NOT NULL,
    adc_samples INT NOT NULL,

    status VARCHAR(32) NOT NULL DEFAULT 'created',

    started_at DATETIME(3) NOT NULL DEFAULT CURRENT_TIMESTAMP(3),
    finished_at DATETIME(3) NULL,

    PRIMARY KEY (id),
    UNIQUE KEY uk_cv_runs_run_id (run_id)
);

CREATE TABLE IF NOT EXISTS cv_samples (
    id BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,
    run_id VARCHAR(48) NOT NULL,

    sample_index INT UNSIGNED NOT NULL,
    elapsed_ms INT UNSIGNED NOT NULL,

    cycle_no INT NOT NULL,
    segment_id INT NOT NULL,
    segment_name VARCHAR(32) NOT NULL,

    potential_set_mv DECIMAL(12,4) NOT NULL,
    potential_est_mv DECIMAL(12,4) NOT NULL,

    dac_raw INT NOT NULL,

    gain_no TINYINT NOT NULL,
    rtia_nominal_ohm DOUBLE NOT NULL,

    adc_raw_mean DOUBLE NOT NULL,
    adc_raw_min INT NOT NULL,
    adc_raw_max INT NOT NULL,
    adc_raw_std DOUBLE NOT NULL,
    ads_v DOUBLE NOT NULL,

    current_na DOUBLE NOT NULL,
    current_ua DOUBLE NOT NULL,

    quality VARCHAR(20) NOT NULL,
    rssi_dbm INT NULL,

    created_at DATETIME(3) NOT NULL DEFAULT CURRENT_TIMESTAMP(3),

    PRIMARY KEY (id),
    UNIQUE KEY uk_cv_sample (run_id, sample_index),
    KEY idx_cv_samples_run_id (run_id),
    KEY idx_cv_samples_cycle (run_id, cycle_no)
);