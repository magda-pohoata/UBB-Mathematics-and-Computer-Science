package Repository;

import model.Car;

import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

public class CarInMemoryRepo extends AbsRepo <Integer,Car> implements CarRepo{

    public List<Car> filterByManufacturer(String manufacturer)
    {
        List<Car> CarsByManufacturer = getAll().stream().filter(car -> car.getManufacturer().toLowerCase().equals(manufacturer.toLowerCase())  ).collect(Collectors.toList());

        return CarsByManufacturer;
    }

    public List<Car> filterByManufacturerAndModel(String manufacturer,String model)
    {
        List<Car> CarsByManufacturerAndModel = getAll().stream().filter(car -> car.getManufacturer().toLowerCase().equals(manufacturer.toLowerCase()) && car.getModel().toLowerCase().equals(model.toLowerCase())).collect(Collectors.toList());

        return CarsByManufacturerAndModel;
    }

    public List<Car> filterByYear(Integer year)
    {
        List<Car> CarsByYear = getAll().stream().filter(car -> car.getYear()>=year).collect(Collectors.toList());

        return CarsByYear;
    }

    public List<Car> filterCheaperPrice(Integer price)
    {
        List<Car> CarsByPrice = getAll().stream().filter(car -> car.getPrice_of_rental()<=price).collect(Collectors.toList());

        return CarsByPrice;
    }

    public List<Car> filterByModel(String model)
    {
        List<Car> CarsByModel = getAll().stream().filter(car -> car.getModel().toLowerCase().equals(model.toLowerCase())).collect(Collectors.toList());

        return CarsByModel;
    }
}
