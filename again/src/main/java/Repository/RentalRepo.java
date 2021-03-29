package Repository;

import model.*;

import java.util.List;

public interface RentalRepo extends Repository<Integer, Rental>{
    List<Rental> filterByNameCustomer(String name);
    List<Rental> filterByDate(String date);
    List<Rental> filterByNoDays(Integer days);
}
