package model;


public class Rental implements Identifiable<Integer>{
    private int ID;
    private String name;
    private String date;
    private int no_days;
    private int carID;

    public Rental(){
        this.ID=0;
        this.carID=0;
        this.date="";
        this.name="";
        this.no_days=0;
    }

    public Rental(int ID, String name, String date,int no_days, int carID) {
        this.ID = ID;
        this.carID = carID;
        this.date = date;
        this.name = name;
        this.no_days=no_days;
    }

    public Rental(String name, String date,int no_days, int carID)
    {
        this.carID = carID;
        this.date = date;
        this.name = name;
        this.no_days=no_days;
    }


    @Override
    public Integer getID() {
        return ID;
    }

    public void setID(Integer ID) {
        this.ID = ID;
    }



    @Override
    public String toString()
    {
        return ""+this.ID+"-"+this.name+"-"+this.date+"-"+this.no_days+"-"+this.carID;
    }

    @Override
    public boolean equals(Object reference)
    {
        if(reference instanceof Rental)
        {
            Rental instance=(Rental) reference;
            return this.ID== instance.ID;
        }
        return false;
    }

    public int getNo_days() {
        return no_days;
    }

    public void setNo_days(int no_days) {
        this.no_days = no_days;
    }

    public void setCarID(int carID) {
        this.carID = carID;
    }

    public int getCarID() {
        return carID;
    }


    public String getDate() {
        return date;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
