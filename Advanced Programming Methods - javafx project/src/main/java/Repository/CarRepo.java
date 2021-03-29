package Repository;

import model.Car;

import java.util.*;

public interface CarRepo extends Repository<Integer, Car>{
    List<Car> filterByManufacturer(String manufacturer);
    //List<Car> filterByManufacturerAndModel(String manufacturer, String model);
    List<Car> filterByYear(Integer year);
    List<Car> filterCheaperPrice(Integer price);
    List<Car> filterByModel(String model);
}
