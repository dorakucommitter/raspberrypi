package com.example.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.example.domain.MeasureData;

public interface MeasureDataRepository extends JpaRepository<MeasureData, Integer>
{

}
