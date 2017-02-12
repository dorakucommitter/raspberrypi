package com.example.lib;

import java.sql.Date;
import java.sql.Timestamp;
import java.text.SimpleDateFormat;

import lombok.Data;

@Data
public class MeasureDataLib
{
    private Integer id;
    private long epochTime;
    private Integer temperature;
    private Integer humid;
    private Integer pressure;
    private Timestamp createAt;

    /**
     * TODO：
     * getEpochTime関数自体はepoch time(long型)で返して、表示する時に文字変換する。
     * グラフ書く時、X軸の値が指定できない。。。
     * @return
     */
    public String getEpochTime()
    {
        return((new SimpleDateFormat("yyyy/MM/dd(EEE) HH:mm:ss")).format((new Date(this.epochTime*1000))));
    }

    /**
     * TODO
     * 測定温度を返す。10で割って小数点表記を返したいが、この方法であってる？
     * @return String 測定温度(小数点第一位)
     */
    public String getTemperature()
    {
        return(((Integer)(this.temperature/10)).toString() + "." + ((Integer)(this.temperature%10)).toString());
    }

    /**
     * TODO
     * 温度と同じで、小数点表記の文字を返したいが、もっとよさ気な方法ない？
     * @return String 測定湿度(小数点第一位)
     */
    public String getHumid()
    {
        return(((Integer)(this.humid/10)).toString() + "." + ((Integer)(this.humid%10)).toString());
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
