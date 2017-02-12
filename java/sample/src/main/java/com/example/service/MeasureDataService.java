package com.example.service;

import java.util.ArrayList;
import java.util.List;

import javax.transaction.Transactional;

import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.example.domain.MeasureData;
import com.example.lib.MeasureDataLib;
import com.example.repository.MeasureDataRepository;

@Service
@Transactional
public class MeasureDataService
{
    @Autowired
    MeasureDataRepository measureRepo;

    /**
     * 測定結果レコード全取得
     * @return List<MeasureDataWeb>
     */
    public List<MeasureDataLib> findAllForWeb()
    {
        List<MeasureData> measureDatas = this.measureRepo.findAll();
        ArrayList<MeasureDataLib> result = new ArrayList<MeasureDataLib>();
        for(MeasureData m : measureDatas) {
            MeasureDataLib tmp = new MeasureDataLib();
            BeanUtils.copyProperties(m, tmp);
            //System.out.println(tmp.toString());
            result.add(tmp);
            tmp = null;
        }
        /*
        for(MeasureDataLib m : result) {
            System.out.println(m.toString());
        }
        */
        return result;
    }
}
