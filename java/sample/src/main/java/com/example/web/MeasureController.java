package com.example.web;

import java.util.ArrayList;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import com.example.service.MeasureDataService;
import com.example.lib.MeasureDataLib;

@Controller
@RequestMapping("/")
public class MeasureController
{
    @Autowired
    MeasureDataService measureServ;

    @RequestMapping("/")
    public String index(Model model)
    {
        ArrayList<MeasureDataLib> results = (ArrayList<MeasureDataLib>) this.measureServ.findAllForWeb();
        /*
        System.out.println(results.size());
        for(MeasureDataLib m : results) {
            System.out.println(m.toString());
        }
        */
        model.addAttribute("results", results);
        return "measure/index";
    }

}
