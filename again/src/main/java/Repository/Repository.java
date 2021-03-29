package Repository;

import model.Identifiable;

import java.util.Collection;

public interface Repository <ID,T extends Identifiable<ID>>{
    T add(T elem);
    void delete(T elem);
    void update(T elem, ID id);
    T findByID(ID id);
    Iterable <T> findAll();
    Collection<T> getAll();
}
