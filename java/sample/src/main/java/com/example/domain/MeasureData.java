package com.example.domain;

import java.sql.Timestamp;
import java.util.Calendar;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.PrePersist;
import javax.persistence.Table;

import lombok.AllArgsConstructor;
import lombok.Data;

@Entity
@Table(name = "measure_data")
@Data
@AllArgsConstructor
public class MeasureData
{
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Integer id;

    @Column(name = "epoch_time")
    private long epochTime;

    @Column
    private Integer temperature;

    @Column
    private Integer humid;

    @Column
    private Integer pressure;

    @Column
    private Timestamp createAt;

    public MeasureData() {}

    public MeasureData(int epochTime, int temperature, int humid, int pressure)
    {
        this.epochTime = epochTime;
        this.temperature = temperature;
        this.humid = humid;
        this.pressure = pressure;
    }

    @PrePersist
    private void preCreate()
    {
        this.setCreateAt(new Timestamp(Calendar.getInstance().getTimeInMillis()));
    }

    @Override
    public String toString()
    {
        return "MeasureData: id = " + this.id
            + " epochTime = " + this.epochTime
            + " temperature = " + this.temperature
            + " humid = " + this.humid
            + " pressure = " + this.pressure
            + " createAt = " + this.createAt;
    }
}
