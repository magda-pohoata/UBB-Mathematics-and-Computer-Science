package Service;

import Repository.CarRepo;
import Repository.RentalRepo;
import Repository.RepoException;
import model.*;

import javax.annotation.processing.RoundEnvironment;
import java.util.List;

public class CarRentalService {

    private CarRepo carRepo;
    private RentalRepo rentalRepo;

    public CarRentalService(CarRepo carRepo, RentalRepo rentalRepo) {
        this.carRepo = carRepo;
        this.rentalRepo = rentalRepo;
    }

    public int addCar(String Manufacturer, String Model, Integer Year, Integer Price,Integer Max_speed) throws ServiceException {
        try {
            Car car = new Car(Manufacturer, Model, Year, Price,Max_speed);
            Car newCar = carRepo.add(car);
            return newCar.getID();
        } catch (RepoException ex) {
            throw new ServiceException("Error adding request" + ex);
        }
    }

    public int addRental(String name, String date, Integer days, Integer carID) throws ServiceException {
        try {
            Rental rental = new Rental(name, date, days, carID);
            Rental newRental=rentalRepo.add(rental);
            return newRental.getID();
        } catch (RepoException er) {
            throw new ServiceException("Error adding form" + er);
        }
    }

    public void deleteCar(Car c) throws ServiceException {
        try
        {
            carRepo.delete(c);
        }catch(RepoException ex){throw new ServiceException("Error deleting Car "+ ex);}
    }

    public void deleteRental(Rental r) throws ServiceException{
        try{
            rentalRepo.delete(r);
        }catch (RepoException ex){throw new ServiceException("Error deleting Rental "+ ex);}
    }

    public void updateCar(Car c,Integer ID)throws ServiceException{
        try{
            carRepo.update(c,ID);
        }catch (RepoException ex){throw new ServiceException("Error deleting Car "+ex);}
    }
    public void updateRental(Rental r,Integer ID)throws ServiceException{
        try{
            rentalRepo.update(r,ID);
        }catch (RepoException ex){throw new ServiceException("Error deleting Rental "+ex);}
    }




    public List<Car> filterByManufacturer(String manufacturer){ return carRepo.filterByManufacturer(manufacturer);}

    /*
    public List<Car> filterByManufacturerAndModel(String manufacturer, String model){
        return carRepo.filterByManufacturerAndModel(manufacturer,model);
    }
     */

    public List<Car> filterByYear(Integer year){
        return carRepo.filterByYear(year);
    }

    public List<Car> filterCheaperPrice(Integer price){
        return carRepo.filterCheaperPrice(price);
    }

    public List<Car> filterByModel(String model){
        return carRepo.filterByModel(model);
    }




/*
    public List<Rental> filterNameCustomerByDate(String date){
        return rentalRepo.filterNameCustomerByDate(date);
    }

    public List<Rental> filterDateByCustomerName(String name){
        return rentalRepo.filterDateByCustomerName(name);
    }

 */

    public List<Rental> filterByDate(String date){
        return rentalRepo.filterByDate(date);
    }

    public List<Rental> filterByNameCustomer(String name){
        return rentalRepo.filterByNameCustomer(name);
    }

    public List<Rental> filterByNoDays(Integer days){
        return rentalRepo.filterByNoDays(days);
    }



    public CarRepo getCarRepo() {
        return carRepo;
    }

    public RentalRepo getRentalRepo() {
        return rentalRepo;
    }
}
