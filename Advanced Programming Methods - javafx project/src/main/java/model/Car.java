package model;


public class Car implements Identifiable<Integer> {
    private int ID;
    private String manufacturer;
    private String model;
    private int year;
    private int price_of_rental;
    private int max_speed;

    public Car(){
        this.ID=0;
        this.manufacturer="";
        this.model="";
        this.year=0;
        this.price_of_rental=0;
        this.max_speed=0;
    }

    public Car(int ID, String manufacturer, String model, int year, int price_of_rental, int max_speed) {
        this.ID = ID;
        this.manufacturer = manufacturer;
        this.model = model;
        this.year = year;
        this.price_of_rental = price_of_rental;
        this.max_speed = max_speed;
    }

    public Car(String manufacturer, String model, int year, int price_of_rental, int max_speed) {
        this.manufacturer = manufacturer;
        this.model = model;
        this.year = year;
        this.price_of_rental = price_of_rental;
        this.max_speed = max_speed;
    }

    @Override
    public Integer getID() {
        return ID;
    }

    public void setID(Integer ID) {
        this.ID = ID;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public void setManufacturer(String manufacturer) {
        this.manufacturer = manufacturer;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getMax_speed() {
        return max_speed;
    }

    public void setMax_speed(int max_speed) {
        this.max_speed = max_speed;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getPrice_of_rental() {
        return price_of_rental;
    }

    public void setPrice_of_rental(int price_of_rental) {
        this.price_of_rental = price_of_rental;
    }

    @Override
    public String toString()
    {
        return ""+this.ID+"-"+this.manufacturer+"-"+this.model+"-"+this.year+"-"+this.price_of_rental+"-"+this.max_speed;
    }

    @Override
    public boolean equals(Object  reference)
    {
        if(reference instanceof Car)
        {
            Car instance=(Car) reference;
            return this.ID== instance.ID;
        }
        return false;
    }
}
