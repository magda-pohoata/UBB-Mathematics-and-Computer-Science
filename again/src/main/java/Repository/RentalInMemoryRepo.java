package Repository;

import model.*;

import java.util.Collection;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class RentalInMemoryRepo extends AbsRepo<Integer, Rental> implements RentalRepo {

    /*
    public List<String> filterNameCustomerByDate(String date)
    {
        List<String> NameCustomerByDate = getAll().stream().filter(x->date.equals(x.getDate())).map(rental -> rental.getName()).collect(Collectors.toList());

        return NameCustomerByDate;
    }

    public List<String> filterDateByCustomerName(String name)
    {
        List<String> ListOfDates=getAll().stream().filter(x->name.toLowerCase().equals(x.getName().toLowerCase())).map(rental -> rental.getDate()).collect(Collectors.toList());

        return ListOfDates;
    }
     */

    public List<Rental> filterByNameCustomer(String name)
    {
        List<Rental> ByNameCustomer = getAll().stream().filter(rental -> rental.getName().toLowerCase().equals(name.toLowerCase()) ).collect(Collectors.toList());

        return ByNameCustomer;
    }

    public List<Rental> filterByDate(String date)
    {
        List <Rental> ByDate = getAll().stream().filter(rental -> rental.getDate().equals(date)).collect(Collectors.toList());

        return ByDate;
    }

    public List<Rental> filterByNoDays(Integer days)
    {
        List <Rental> ByDays = getAll().stream().filter(rental -> rental.getNo_days()<=days).collect(Collectors.toList());

        return ByDays;
    }
}
