<template>
  <div class="col-4 py-4">
    <h3>{{ name }}</h3>
    <h1>{{ value }} / 3</h1>
  </div>
</template>

<script>
import { database } from 'firebase'
export default {
  name: 'DataCard',
  props: ['name', 'path', 'data'],
  data () {
    return {
      value: null
    }
  },
  mounted () {
    if (this.path != null) {
      let data = database().ref(this.path)
      let self = this
      data.on('value', function(snapshot) {
          self.value = snapshot.val()
      })
    } else {
      this.value = this.data
    }
  },
  watch: {
    data () {
      this.value = this.data
    }
  }
}
</script>

<style lang="scss" scoped>
  div{
    // padding: 3%;
    margin-top: 5%;
    background-color: yellow;
  }
  h1{
    font-size: 3rem;
  }
</style>
